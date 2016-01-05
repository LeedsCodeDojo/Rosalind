input = 
    case System.argv() do
        ["-f"|filename] -> 
            {:ok, text} = File.read "#{filename}"
            String.strip(text)
        [_|[text|_]] -> text
    end

complements = 
    %{ "C" => "G",
       "G" => "C",
       "A" => "T",
       "T" => "A"}
      
input 
|> String.reverse 
|> String.codepoints
|> Enum.map(fn(item) -> complements[item] end)
|> IO.puts