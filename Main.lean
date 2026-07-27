module

public import LMLExposition

@[expose] public section

open LMLExposition

unsafe def main (args : List String) : IO UInt32 :=
  mainImpl args
