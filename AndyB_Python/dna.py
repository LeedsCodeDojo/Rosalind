
from collections import Counter
from string import translate, maketrans

NUCLEOTIDES = 'ACGT'

def countNucleotides(dna):
    """
    Count the number of occurrences of each nucleotide in a DNA Sequence
    """
    counter = Counter(dna)
    return ' '.join(map(str,[counter[x] for x in NUCLEOTIDES])) 
    
def transcribeDnaToRna(dna):
    """
    Convert a DNA sequence to RNA
    Just use replace thymine (T) with uracil (U)
    """
    return dna.replace('T','U')

def reverseComplement(dna):
    """
    Generate the Reverse Complement of a DNA Sequence
    Translate & then reverse.
    
    DNA is composed of 2 complementary strands which run in opposite directions.
    This allows DNA to divide & replicate and to produce 2 strands of mRNA.
    """
    return dna.translate(maketrans(NUCLEOTIDES,NUCLEOTIDES[::-1]))[::-1]

def hammingDistance(sequence1, sequence2):
    """
    Calculate the Hamming Distance between 2 sequences.
    
    This is a rough calculation of the number of changes between pairs of sequences.
    """
    return sum(map(lambda x, y: 1 if x!=y else 0, sequence1, sequence2))

def gcContentPercentage(dna):
    """
    Calculate the percentage of the DNA which is either a 'G' or a 'C'
    
    This can be used to locate regions rich in CG pairs called 'CpG islands' in the chain of DNA.
    These regions often indicate locations in the DNA Sequence in which genes start.
    """
    return 100.0 * sum(map(lambda x: 1 if x in 'CG' else 0, dna))/float(len(dna))
