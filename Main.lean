module

public import Referee

@[expose] public section

open Referee

unsafe def main (args : List String) : IO UInt32 :=
  mainImpl args
