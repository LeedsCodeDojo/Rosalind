import unittest 
from fasta import read_fasta

class FastaTest(unittest.TestCase):
    def testReadFasta(self):
        with open('data/gcContent.fasta') as fp:
            seqs = list(read_fasta(fp))
            self.assertIsNotNone(seqs)
            self.assertEqual(7, len(seqs))
