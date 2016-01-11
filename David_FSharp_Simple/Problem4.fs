module Problem4

let solve (n:int) (k:int) : int64 =
    let k' = (int64) k
    let result = [3..n] |> Seq.fold (fun state _ -> let (lastMonth,finalMonth) = state
                                                    (finalMonth, (lastMonth * k') + finalMonth))
                                                    (1L, 1L)
    let (last,finalMonth) = result
    finalMonth

solve 31 5 = 14415648500221L
