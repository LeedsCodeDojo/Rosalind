data = 'GATGGAACTTGACTACGTAAATT'

puts data.split('').map{|el| el == 'T' ? 'U' : el }.join('')
