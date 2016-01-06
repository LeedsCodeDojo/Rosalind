Problem 4 - Rabbits and Recurrence Relations
============================================

## Background: Wascally Wabbits

In 1202, Leonardo of Pisa (commonly known as Fibonacci) considered a mathematical exercise regarding the reproduction of a population of rabbits. He made the following simplifying assumptions about the population:

* The population begins in the first month with a pair of newborn rabbits.
* Rabbits reach reproductive age after one month.
* In any given month, every rabbit of reproductive age mates with another rabbit of reproductive age.
* Exactly one month after two rabbits mate, they produce one male and one female rabbit.
* Rabbits never die or stop reproducing.

Fibonacci's exercise was to calculate how many pairs of rabbits would remain in one year. We can see that in the second month, the first pair of rabbits reach reproductive age and mate. In the third month, another pair of rabbits is born, and we have two rabbit pairs; our first pair of rabbits mates again. In the fourth month, another pair of rabbits is born to the original pair, while the second pair reach maturity and mate (with three total pairs).

## Background: Sequences and Recurrence Relations

A sequence is an ordered collection of objects (usually numbers), which are allowed to repeat. Sequences can be finite or infinite. Two examples are the finite sequence (PI,-2,0,PI) and the infinite sequence of odd numbers (1,3,5,7,9,…). We use the notation a<sub>n</sub> to represent the n-th term of a sequence.

A recurrence relation is a way of defining the terms of a sequence with respect to the values of previous terms. In the case of Fibonacci's rabbits from the introduction, any given month will contain the rabbits that were alive the previous month, plus any new offspring. A key observation is that the number of offspring in any month is equal to the number of rabbits that were alive two months prior. As a result, if F<sub>n</sub> represents the number of rabbit pairs alive after the n-th month, then we obtain the Fibonacci sequence having terms F<sub>n</sub> that are defined by the recurrence relation F<sub>n</sub>=F<sub>n-1</sub>+F<sub>n-2</sub> (with F<sub>1</sub>=F<sub>2</sub>=1 to initiate the sequence). Although the sequence bears Fibonacci's name, it was known to Indian mathematicians over two millennia ago.

When finding the n-th term of a sequence defined by a recurrence relation, we can simply use the recurrence relation to generate terms for progressively larger values of n. This problem introduces us to the computational technique of dynamic programming, which successively builds up solutions by using the answers to smaller cases.

## Problem

**Given**: Positive integers n<=40 and k<=5.

**Return**: The total number of rabbit pairs that will be present after n months if we begin with 1 pair and in each generation, every pair of reproduction-age rabbits produces a litter of k rabbit pairs (instead of only 1 pair).

Sample Dataset

    5 3
    
Sample Output

    19

*Note:* The description for this isn't great, but the solution's relatively straightforward.  If you can get a Fibonacci function working, the problem just requires a slight modification related to the 'give birth to three pairs' part.  Pay attention to when the rabbit pairs reach maturity, which is one month after being born (hence the births are based on the n-2 number).
