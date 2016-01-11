[<AutoOpen>]
module Utilities

let calculateGCContent (dna:string) : double =
    100.0 / (float dna.Length) *
    (dna |> Seq.sumBy (fun c -> if c = 'C' || c = 'G' then 1.0 else 0.0))

//calculateGCContent "AGCTATAG" = 37.5