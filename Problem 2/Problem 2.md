Problem 2 - Transcribing DNA into RNA
=====================================

An RNA string is a string formed from the alphabet containing 'A', 'C', 'G', and 'U'.

Given a DNA string t corresponding to a coding strand, its transcribed RNA string u is formed by replacing all occurrences of 'T' in t with 'U' in u.

**Given**: A DNA string t having length at most 1000 nt.

**Return**: The transcribed RNA string of t.

###Sample Dataset

    GATGGAACTTGACTACGTAAATT
    
###Sample Output

    GAUGGAACUUGACUACGUAAAUU

*Note*: This is rather easy to achieve with a simple string replacement, so to make it a bit more challenging you might want to implement it yourself using, for instance, iteration or recursion over the list of characters.
