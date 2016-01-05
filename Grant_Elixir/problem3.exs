content = 
    case System.argv() do
        ["-f"|filename] -> 
            {:ok, text} = File.read "#{filename}"
            text
        [_|[text|_]] -> text
    end

complements = 
    %{ "C" => "G",
       "G" => "C",
       "A" => "T",
       "T" => "A"}
      
content 
|> String.reverse 
|> String.codepoints
|> Enum.map(fn(item) -> complements[item] end)
|> IO.puts