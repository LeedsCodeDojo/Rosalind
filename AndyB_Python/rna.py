from itertools import takewhile

# Table which maps Codons to Proteins
rnaCoding = {'ACC': 'T', 'GCA': 'A', 'AAG': 'K', 'AAA': 'K', 'GUU': 'V', 'AAC': 'N', 'AGG': 'R', 'UGG': 'W', 'GUC': 'V',
             'AGC': 'S', 'ACA': 'T', 'AGA': 'R', 'AAU': 'N', 'ACU': 'T', 'GUG': 'V', 'CAC': 'H', 'ACG': 'T', 'AGU': 'S',
             'CCA': 'P', 'CAA': 'Q', 'CCC': 'P', 'UGU': 'C', 'GGU': 'G', 'UCU': 'S', 'GCG': 'A', 'CGA': 'R', 'CAG': 'Q',
             'CGC': 'R', 'UAU': 'Y', 'CGG': 'R', 'UCG': 'S', 'CCU': 'P', 'GGG': 'G', 'GGA': 'G', 'GGC': 'G', 'CCG': 'P',
             'UCC': 'S', 'UAC': 'Y', 'CGU': 'R', 'GAA': 'E', 'AUA': 'I', 'AUC': 'I', 'CUU': 'L', 'UCA': 'S', 'AUG': 'M',
             'UGA': 'STOP', 'CUG': 'L', 'GAG': 'E', 'AUU': 'I', 'CAU': 'H', 'CUA': 'L', 'UAA': 'STOP', 'GCC': 'A',
             'UUU': 'F', 'GAC': 'D', 'GUA': 'V', 'UGC': 'C', 'GCU': 'A', 'UAG': 'STOP', 'CUC': 'L', 'UUG': 'L', 'UUA': 'L', 'GAU': 'D', 'UUC': 'F'}


def rnaTranslation(rna):
    """
    Translate an RNA Sequence to a Protein Sequence
    Stops translation at 1st 'STOP' Codon 
    """
    def translateCodons(rna):
        """
        Generator which translates each Codon 
        """
        for i in xrange(0,len(rna),3):
            yield rnaCoding[rna[i:i+3]]
    return ''.join(takewhile(lambda x: x!='STOP', translateCodons(rna)))
        