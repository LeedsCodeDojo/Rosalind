data = 'AAAACCCGGT'

puts Hash[data.split('').group_by{|x| x}.map{|k,v| [k,v.count]}].sort_by{|k, _| k}.inspect
