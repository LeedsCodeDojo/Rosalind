
from collections import Counter
from string import translate, maketrans

def countNucleotides(dna):
    """
    Count the number of occurrences of each nucleotide in a DNA Sequence
    """
    counter = Counter(dna)
    return ' '.join(map(str,[counter['A'],counter['C'],counter['G'],counter['T']])) 
    
def transcribeDnaToRna(dna):
    """
    Convert a DNA sequence to RNA
    """
    return dna.replace('T','U')

def reverseComplement(dna):
    """
    Generate the Reverse Complement of a DNA Sequence
    Translate & then reverse
    """
    return dna.translate(maketrans('ACGT','TGCA'))[::-1]

def hammingDistance(sequence1, sequence2):
    """
    Calculate the Hamming Distance between 2 sequences
    """
    return sum(map(lambda x, y: 1 if x!=y else 0, sequence1, sequence2))

def gcContentPercentage(dna):
    """
    Calculate the percentage of the DNA which is either a 'G' or a 'C'
    """
    counter = Counter(dna)
    return 100.0 * (counter['C'] + counter['G'])/float(len(dna))
