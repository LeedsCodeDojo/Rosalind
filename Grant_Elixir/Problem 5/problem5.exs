[filename|_] = System.argv()
{:ok, input} = File.read filename

defmodule Problem do
    def structure_fasta(input) do
        id = String.slice(input,0..12)
        data = 
            input 
            |> String.slice(14..String.length(input)) 
            |> String.replace("\r\n", "")
        {id,data}
    end
    
    def calculate_gc_content(fasta) do
        {id, text} = fasta
        gc_count = 
            text
            |> String.codepoints
            |> Enum.count(&(&1 == "G" || &1 == "C"))
            
        {id, (gc_count / String.length(text)) * 100}
    end
end

{max_id, max_content} =  
input
|> String.split(">") 
|> Enum.map(&(Problem.structure_fasta(&1)))
|> Enum.drop(1)
|> Enum.map(&(Problem.calculate_gc_content(&1)))
|> Enum.max_by(fn({_,gc_content}) -> gc_content end)

IO.puts("#{max_id}\r\n#{max_content}")
