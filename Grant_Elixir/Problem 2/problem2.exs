content = 
    case System.argv() do
        ["-f"|filename] -> 
            {:ok, text} = File.read "#{filename}"
            text
        [_|[text|_]] -> text
    end

defmodule Problem do
    def replace(input_text, char_to_replace, replace_with) do
        dna_chars = String.codepoints(input_text)
        rna_chars = replace_char(dna_chars, char_to_replace, replace_with)
        Enum.join(rna_chars)
    end
    
    def replace_char(input_chars, char_to_replace, replace_with) do
        case input_chars do
            [] -> []
            [char|rest] when char == char_to_replace -> [replace_with | replace_char(rest, char_to_replace, replace_with)]
            [char|rest] -> [char | replace_char(rest, char_to_replace, replace_with)]
        end
    end
end
      
content |> Problem.replace("T", "U") |> IO.puts