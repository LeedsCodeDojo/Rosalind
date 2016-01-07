
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
    Crude implememntation could be more elegantly written as map + lambda
    """
    fib_table = []
    for i in range(n):
        if i < 2:
            fib_table.append(1)
        else:
            fib_table.append(fib_table[-1] + fib_table[-2]*multiplier)
    return fib_table[-1]

def mortalFibonacci(n, lifespan):
    """
    Generate Fibonacci Sequence with Lifespan
    NB Uses Dynamic programming
    Crude implememntation could be more elegantly written as map + lambda
    """
    fib_table = []
    deaths = ([0] * (lifespan-2)) + [1] 
    for i in range(n):
        if i < 2:
            fib_table.append(1)
        else:
            fib_table.append(fib_table[-1] + fib_table[-2]-deaths[0])
            deaths = deaths[1:] + [fib_table[-3]]
    return fib_table[-1]
