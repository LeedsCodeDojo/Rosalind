import unittest

import operator
from dna import countNucleotides, transcribeDnaToRna, reverseComplement,\
                hammingDistance, gcContentPercentage
from fasta import read_fasta

class DnaTest(unittest.TestCase):

    def testCountNucleotides(self):
        dna = 'AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC'
        self.assertEqual('20 12 17 21', countNucleotides(dna))

    def testTranscribeDnaToRna(self):
        dna = 'GATGGAACTTGACTACGTAAATT'
        self.assertEqual('GAUGGAACUUGACUACGUAAAUU', transcribeDnaToRna(dna))
        
    def testReverseComplement(self):
        dna = 'AAAACCCGGT'
        self.assertEqual('ACCGGGTTTT', reverseComplement(dna))

    
    def testHammingDistance(self):
        sequence1, sequence2 = 'GAGCCTACTAACGGGAT', 'CATCGTAATGACGGCCT'
        self.assertEqual(7, hammingDistance(sequence1, sequence2))
        
    def testHammingDistanceFromFile(self):
        with open('data/hammingDistance.txt') as fp:
            sequence1, sequence2 = map(lambda x: x.strip(), fp.readlines())
            self.assertEqual(483, hammingDistance(sequence1, sequence2))
    
    
    def testGcContentPercentage(self):
        self.assertEqual(37.5, gcContentPercentage('AGCTATAG'))
        
    def testGcContentPercentageFromFile(self):
        with open('data/gcContent.fasta') as fp:
            gcContents = {name: gcContentPercentage(seq) 
                               for name, seq in read_fasta(fp)}
            maxName, maxGc = max(gcContents.iteritems(), key=operator.itemgetter(1))
            self.assertEqual('Rosalind_6020', maxName)
            self.assertAlmostEqual(51.881994, maxGc, places=5)

        