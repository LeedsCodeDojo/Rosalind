data = 'AAAACCCGGT'
complements = {'A' =>'T', 'C' =>'G', 'T' =>'A', 'G'=>'C'}

puts data.reverse.split('').map{|el| complements[el]}.join('')
