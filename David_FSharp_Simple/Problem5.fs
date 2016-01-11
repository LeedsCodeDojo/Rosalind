// Add the FParsec NUGET package

#if INTERACTIVE
#r "C:\\Compiler\\LogoTest\\packages\\FParsec.1.0.2\\lib\\net40-client\\FParsecCS.dll"
#r "C:\\Compiler\\LogoTest\\packages\\FParsec.1.0.2\\lib\\net40-client\\FParsec.dll"
#else
module Problem5
#endif

open FParsec

type Fasta =
    {
        Label : string
        Dna : string
    }

let solve (filename:string) : string =
    let loadFile (filename:string) : List<Fasta> = 
    
        let pID = (pstring ">Rosalind_" >>. manySatisfy isDigit ) |>> (fun d ->  "Rosalind_" + d)
        let pDNA = manySatisfy (function | 'A' | 'T' | 'G' | 'C' -> true | _ -> false)
        let pFasta = pipe2 (pID .>> newline) (many (pDNA .>> newline)) (fun label dnas -> {Fasta.Label = label; 
                                                                                           Fasta.Dna = System.String.Concat dnas} )

        match run (many pFasta) (System.IO.File.ReadAllText(filename)) with
        | Success(result, _, _)   -> result
        | Failure(errorMsg, _, _) -> failwith (sprintf "Parsing the file %s failed with the error %s" filename errorMsg)

    let result =
        loadFile filename
            |> List.map (fun fasta -> fasta, calculateGCContent fasta.Dna )
            |> List.maxBy (fun (_, calc) -> calc)
     
    sprintf "%s\n%f" (fst result).Label (snd result)

solve "C:\CodeDojo\Rosalind\Problem 5\problem_5_dataset.txt"
