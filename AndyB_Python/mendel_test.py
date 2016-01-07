import unittest
from mendel import mendelsFirstLaw

class MendelTest(unittest.TestCase):

    def testMendelsFirstLaw(self):
        params = (2,2,2)
        self.assertAlmostEqual(0.78333, mendelsFirstLaw(*params), places=5)
