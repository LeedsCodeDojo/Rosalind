input = 
    case System.argv() do
        ["-f"|filename] -> 
            {:ok, text} = File.read "#{filename}"
            text |> String.strip
        [_|text] -> text |> Enum.join " "
    end

defmodule Problem do
    def fib(n,k) do
        case n do
            1 -> 1
            2 -> 1
            _ -> fib(n-1, k) + fib(n-2, k) * k
        end
    end
end
      
[n,k] = (input |> String.split |> Enum.map(&String.to_integer(&1)))

Problem.fib(n,k)
|> IO.puts
