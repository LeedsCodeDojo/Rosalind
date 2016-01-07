import unittest
from fibonacci import fibonacci, fibonacciDynamic, mortalFibonacci

class FibonacciTest(unittest.TestCase):
    def testFibonacci(self):
        self.assertEqual(19, fibonacci(5,3))

    def testFibonacciDynamic(self):
        self.assertEqual(19, fibonacciDynamic(5,3))

    def testMortalFibonacci(self):
        self.assertEqual(4, mortalFibonacci(6,3))

