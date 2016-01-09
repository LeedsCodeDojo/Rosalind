import unittest

from rna import rnaTranslation

class rnaTest(unittest.TestCase):
    
    def testRnaTranslation(self):
        rna = 'AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA'
        self.assertEqual('MAMAPRTEINSTRING', rnaTranslation(rna))

    def testRnaTranslationFromFile(self):
        with open('data/rnaTranslation.txt') as fp:
            with open('data/rnaTranslationAnswer.txt') as answerFile:
                expectedProtein = answerFile.readline().strip()
                rna = fp.readline().strip()
                self.assertEqual(expectedProtein, rnaTranslation(rna))
            
