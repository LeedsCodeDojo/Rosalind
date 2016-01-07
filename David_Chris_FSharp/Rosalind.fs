
let solveProblem1 dataset =
    let result = 
        dataset |> Seq.fold (fun s c -> let As, Cs, Gs, Ts = s
                                        match c with
                                         | 'A' ->  (As + 1, Cs, Gs, Ts)
                                         | 'C' ->  (As, Cs + 1, Gs, Ts)
                                         | 'G' ->  (As, Cs, Gs + 1, Ts)
                                         | 'T' ->  (As, Cs, Gs, Ts + 1))
                        (0, 0, 0, 0)
    sprintf "%A" result

let solveProblem2 (dataset:string) =

    // Active pattern match,  if the array starts with this character then we return the rest of the array
    let (|StartsWith|_|) (pattern:char) (toMatch:char[]) =
        if toMatch.[0] = pattern then 
            Some(toMatch.[1..])
        else 
            None

    let rec inner = function
                    | [||] -> [||]
                    | StartsWith 'T' restOfLine -> Array.append [|'U'|] (inner restOfLine)
                    | x -> Array.append [|(x |> Array.head)|] (inner (x |> Array.tail))

    inner (dataset.ToCharArray())
    |> System.String.Concat

let solveProblem3 (dataset:string) =
    let (|StartsWith|_|) (pattern:char) (toMatch:char[]) =
        if toMatch.[0] = pattern then 
            Some(toMatch.[1..])
        else 
            None

    let rec inner = function
                    | [||] -> [||]
                    | StartsWith 'A' restOfLine -> Array.append (inner restOfLine) [|'T'|] 
                    | StartsWith 'T' restOfLine -> Array.append (inner restOfLine) [|'A'|] 
                    | StartsWith 'C' restOfLine -> Array.append (inner restOfLine) [|'G'|] 
                    | StartsWith 'G' restOfLine -> Array.append (inner restOfLine) [|'C'|] 
                    | x -> Array.append [|(x |> Array.head)|] (inner (x |> Array.tail))

    inner (dataset.ToCharArray()) |> System.String.Concat

let solveProblem4 n k =
    let k' = (int64) k
    let result = [3..n] |> Seq.fold (fun state _ -> let (lastMonth,finalMonth) = state
                                                    (finalMonth, (lastMonth * k') + finalMonth))
                                                    (1L, 1L)
    let (last,finalMonth) = result
    finalMonth

type Fasta =
    {
        Label : string
        Dna : string
    }

let solveProblem5 filename =
    let loadFile filename = 
    
        let rec inner fastaInProgress fastas (linesNotProcessed : string[]) =
            match linesNotProcessed with
            | [||] -> fastaInProgress :: fastas
            | a when (a |> Array.head).StartsWith(">") ->
                                          let thisLine = a |> Array.head
                                          inner {Fasta.Label = thisLine; Fasta.Dna=""} (fastaInProgress :: fastas) (a |> Array.tail)
            | a -> let thisLine = a |> Array.head
                   inner {fastaInProgress with Dna = fastaInProgress.Dna + thisLine} fastas (a |> Array.tail)
    
        let allLines = System.IO.File.ReadAllLines(filename)
        inner {Fasta.Label = ""; Fasta.Dna=""} [] allLines

    let calculateGCContent (dna:string) : double =
        100.0 / (float dna.Length) *
        (dna |> Seq.sumBy (fun c -> if c = 'C' || c = 'G' then 1.0 else 0.0))

    let result =
        loadFile filename
            |> List.map (fun fasta -> fasta, calculateGCContent fasta.Dna )
            |> List.maxBy (fun (_, calc) -> calc)
     
    sprintf "%s\n%f" (fst result).Label (snd result)

let solveProblem6 (s:string) (t:string) : int =
    s.ToCharArray() 
        |> Array.zip (t.ToCharArray())
        |> Array.filter (fun (a, b) -> a <> b)
        |> Array.length

