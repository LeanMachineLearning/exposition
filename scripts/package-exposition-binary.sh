#!/usr/bin/env bash

set -euo pipefail

output_dir="${1:-dist}"
binary_path="${BINARY_PATH:-.lake/build/bin/exposition}"
platform="${PACKAGE_PLATFORM:-linux-x86_64}"
source_sha="${SOURCE_SHA:-${GITHUB_SHA:-$(git rev-parse HEAD)}}"
lean_toolchain="$(tr -d '\n' < lean-toolchain)"
built_at_utc="${BUILD_TIMESTAMP_UTC:-$(date -u +%Y-%m-%dT%H:%M:%SZ)}"
asset_stem="exposition-${platform}-${source_sha}"
package_root="${asset_stem}"
staging_dir="${output_dir}/${package_root}"
metadata_path="${output_dir}/${asset_stem}.metadata.json"
archive_path="${output_dir}/${asset_stem}.tar.gz"
checksum_path="${output_dir}/SHA256SUMS"

if [[ ! -x "${binary_path}" ]]; then
  echo "expected built binary at ${binary_path}" >&2
  exit 1
fi

rm -rf "${staging_dir}"
mkdir -p "${staging_dir}"
cp "${binary_path}" "${staging_dir}/exposition"
cp lean-toolchain "${staging_dir}/lean-toolchain"

cat > "${staging_dir}/metadata.json" <<EOF
{
  "name": "exposition",
  "platform": "${platform}",
  "source_sha": "${source_sha}",
  "lean_toolchain": "${lean_toolchain}",
  "built_at_utc": "${built_at_utc}"
}
EOF

cp "${staging_dir}/metadata.json" "${metadata_path}"
tar -C "${output_dir}" -czf "${archive_path}" "${package_root}"
rm -rf "${staging_dir}"

(
  cd "${output_dir}"
  sha256sum "$(basename "${archive_path}")" "$(basename "${metadata_path}")" > "$(basename "${checksum_path}")"
)

echo "packaged ${archive_path}"
