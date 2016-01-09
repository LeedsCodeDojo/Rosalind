
def fibonacci(n, multiplier=1):
    """
    Generate Fibonacci Sequence
    fib(n) = fib(n-1) + fib(n-2)*multiplier

    NB Uses recursion rather than Dynamic programming
    """
    if n <= 2:
        return 1
    return fibonacci(n-1, multiplier) + fibonacci(n-2, multiplier) * multiplier
    
def fibonacciDynamic(n, multiplier=1):
    """
    Generate Fibonacci Sequence
    NB Uses Dynamic programming
    """
    def processGeneration(populationHistory,generationCount):
        generationSize = populationHistory[-1] + populationHistory[-2] * multiplier
        populationHistory.append(generationSize)
        return populationHistory[1:]
    initialPopulation = [0,1]
    return reduce(processGeneration, xrange(n-1), initialPopulation)[-1]

def mortalFibonacci(n, lifespan):
    """
    Generate Fibonacci Sequence with Lifespan
    NB Uses Dynamic programming so that sufficent generations are held in list
    Last element of returned list contains the final generation
    """
    def processGeneration(populationHistory,generationCount):
        generationSize = populationHistory[-1] + populationHistory[-2] - populationHistory[0]
        populationHistory.append(generationSize)
        return populationHistory[1:]
    initialPopulation = ([0] * (lifespan-1)) + [1]
    return reduce(processGeneration, xrange(n), initialPopulation)[-1]
