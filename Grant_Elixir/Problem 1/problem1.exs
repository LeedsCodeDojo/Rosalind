content = 
    case System.argv() do
        ["-f"|filename] -> 
            {:ok, text} = File.read "#{filename}"
            text
        [_|[text|_]] -> text
    end

defmodule Problem do
    def count(text, char) do
        chars = String.codepoints(text)
        Enum.count(chars, fn(item) -> item == char end)
    end
end
      
["A", "C", "G", "T"]
|> Enum.map(&Problem.count(content,&1))
|> Enum.join(" ")
|> IO.puts      