#include <stdio.h>
#include <stdlib.h>

#define PROBLEM_4

#if defined(PROBLEM_1)
const char *pDNA = {"AACAATTTCGATTTCGGCTGCATGGAAGCGGGCAGTAGTCGAGTTCCAGAGAAAAGTCAAAAAGCGGTTGCCAGTTGATACCAATCGGGCGATTGGCACGTAGGTGCGTGCCAGCGTGGCATCCTGTTCGCCGTTCTTAGACAGGCGCAGAGTTTATACGATATATGCGCCACCTCGGGTCGAGACCACTTCGTATCGGCTCCCATCTAGGCTGTCAGATCGGATCCTGCACGCCATATGGCGGGTGCCATTGTCTATGGACGATGGCTGCCTGATGCCGTCTCTCTGTTTAATCAGAAGGTGCGACGGTGGCTGGGCAACTAGTTATTCGGTAAGCACATAAGCTCACGCCCAATTAACATCAGGACACCTAAACAGATCCATATTAAGAGCCACTTAGCGTGCCTGTGTTTCAATTAATCACAAACACCAGGAACATGGGATTGCTCGCACGCGTATGTTATTCGTACAGGTCAAAACCCGTTGTCCCTGAGAGACCTCCGTCCGGGGTCAACGCGCCGTGTGCACCGCGCCATGTCAACGCATTCGTACCAATTCTTACAAATTGTCCAATAGAGAGACCGGCGAGGTGTTTGAGACCGCTGGATAAGAACCAATGCTTGCTGATTATCCTGTCAGTGGGCAGAAAAAAGCGCGCGAATCTTGGGCGAGTGCGGCGTTAGTGATGGTAGCCGATTATCAGTGTCCCCATTAGAATCACCCTCTATACTTGGGCATATTGCGCAGTGCAGGTCCAATATCCATACAAGACGGAAAGACCAACACGATCGTGTGGCTAACTGAGTGTGTTACAATTCAGCCCGGGGACACGATGAACGCCGCTGTAGAACGCCACGCGTCATGGACTTTAACCCAGCGTAATAATGCAGTCGCGTG"};
#elif defined(PROBLEM_2)
const char *pDNA = {"CGUUAGCUGACCGGUCAUUAAUUUGCUUUCUUUGCCUAGAUAGAUUUUCCUUGUAGCCAGCGAGUUUAACGAUAACCUCAAGCUCCGCGCCGAUAACUAUAUUAUUUCAGGCGGGUUACCCUUGCAUGGUUCAUCUUGCAUCAAUUCCGGUGGCUGGAAGGUGGGACAGCCAGUUAGCUGAGGGUUACUGUAGUGUUUCAGUGGUAUUUCCGAUACGCGUUGUGCGGCGAGUGAACCUUCGAUGGAGGAAGCCUAGCCGCGGGGGGGAUAUGUCAAUUGUGUCGCGUGCUUUUAACCAAGACCAAGUUUGAAUAUUGCCUAUGGCCACCAUCCUUAUCUGAGGAAUGUAGGUAUCGCGAGCUCCAGGGUUGAGCUUGCGUAUAGAAGUACCACCUCCUCGCAUCGUACCAGCGGGACACCCUAGCCCCUAUCGCUCCUUGAAAUGGAGAGGUUGAGCUACGUAUACAAAAACCAUUCAGUUCUUACUUAUCGACCGGAGGUCCAUAACUAGGGUCCAUGUCAUAAAAGAUAUGCCUGGUGUGUACAUACUGUAUUAGUCAGCGAACAGGACGGUGCCUCCCGGCCUGAUACAGCGGCCCACCGAGAAUGCUUUAACACAUUGACCAGGGCUGUUUAAGUGUCCCGUGUUGGCUAAAAUGCCUCCCUAUGUAACUUUGUUCCCAUCCGAAUGGCAGAAUUCCGGGCAGAGUGCCAGCCCUUUUCCUACAUAAGGUGGGCUAUACGCAAUCAUGUGCUAGUGUUAGACAGCUGAUCUUGUCUACUGUCGCCCCGUUGCGUGCCAAGGGUCCGCUCUAUGCAAUUGAUAUGAGAUAUAUCCAGCAGGGUACAGUGAGAGUUCUACUUCGUUGCUAUCAUUUUGCACUUGCCUCCCUGGCCACAACUUGCUCAGUUUAGCGAGUAGGACUUGUGAUCUUAUCGAAUAAUU"};
#elif defined(PROBLEM_3)
const char *pDNA = {"ACCGGTTCGTGCGAAGTCAGGATATAATAATTTCCACCAATGTCACTGCGGCCCAAATGCTACTATTCTAAAGCGGTAGGAGAAGTTCGGACCTGTATTAGGTAATAGCCCCATACCTCCACATGTGACCCTACAGGAGTGTACCTTATCCTTCAACCGGTCACCTTAGCGCCGTATAAAAGAGACCATTAAGGAGCCATTTGGGCAGAGATAGTTAGTCGGCGCCCGGGATTAGGGGAAGCCTAGACTGGGCAACTGTTGCTAAGGCTAATGAGCACGGGATAAGAGGACCTCGACCTGGACGAGAGCCAGGCGAAGGGTTATGACTAGCACTGTGGAGACCCGTCCAGCCTACACGCGGTGAGCTCCTGGGACCTCACGCCGGCCCACCGTCTCTGAAGGATCTCCAGGGGGTAATCCCTTTTCCAGAATGTAAGCTTTAAGAGCACTTAAGTGTCGACGGACAGTGACGCCAATAAATTCCCTACACCGATTACTGAGGGATCTTGTAGTACACTGTGAGCTCGTACGGGGATCTTTTCCATTAGCAATCCCGACGCACACCTGCACAGGGACGCACCCGACCGCCCTTGTCGGCAACGGAACTTGCGCGGAGAGGGCAACTGTCTATTGACCTCGAAGAATATGACTCAACTCCCTGTGTTGTTGCGACGGGTGAGGAGGAAGTAGACGAAGGAACAATCCGTCAATTCATCCCACTTCAGAAGTCGGCACGTTGATATGTAATGCTTGATGAGGACATACTGCCAGCTGTCATCACCTGCTAGACCCGGGATTTTATCGCTCGGTAGCGAATAGAGACATCCCTATAGTCTCGGATATCCCCTG"};
#elif defined(PROBLEM_4)
const int pairs = 5;
const int numMonths = 31;
#elif defined(PROBLEM_5)
float extractPercentGC(const char *pDNA)
{
    int     a;
    int     len;
    int     len2 = 0;
    int     counter = 0;
    float   fPercent = 0.0f;

    if (pDNA)
    {
        len = strlen(pDNA);

        for (a = 0; a < len; a ++)
        {
            if (pDNA[a] == 'G' || pDNA[a] == 'C')
            {
                counter ++;
            }

            if (pDNA[a] != '\0' && pDNA[a] != 10 && pDNA[a] != 13)
            {
                len2 ++;
            }
        }

        fPercent = (float)counter / len2 * 100.0f;
    }

    return fPercent;
}
#elif PROBLEM_6

#endif

int main()
{
    int a;

#if defined(PROBLEM_1)
    int len = strlen(pDNA);
    int counterA = 0;
    int counterC = 0;
    int counterG = 0;
    int counterT = 0;

    printf("Counting DNA nucleotides\n");

    for (a = 0; a < len; a ++)
    {
        switch (pDNA[a])
        {
        case 'A':
            counterA ++;

            break;

        case 'C':
            counterC ++;

            break;

        case 'G':
            counterG ++;

            break;

        case 'T':
            counterT ++;

            break;
        }
    }

    printf("%d %d %d %d\n", counterA, counterC, counterG, counterT);
#elif defined(PROBLEM_2)
    int len = strlen(pDNA);

    printf("Transcribing DNA into RNA\n");

    char *pRNA = (char *)malloc(sizeof(char) * (len + 1));

    strcpy(pRNA, pDNA);

    for (a = 0; a < len; a ++)
    {
        if (pRNA[a] == 'T')
        {
            pRNA[a] = 'U';
        }
    }

    printf("%s\n", pRNA);

    free(pRNA);
#elif defined(PROBLEM_3)
    int len = strlen(pDNA);

    printf("Complementing a Strand of DNA\n");

    for (a = len - 1; a >= 0; a --)
    {
        switch (pDNA[a])
        {
        case 'A':
            printf("T");

            break;

        case 'C':
            printf("G");

            break;

        case 'G':
            printf("C");

            break;

        case 'T':
            printf("A");

            break;
        }
    }

    printf("\n");
#elif defined(PROBLEM_4)
    long long prevPairs;
    long long finalPairs;
    long long newPairs;

    for (a = 0; a < numMonths; a ++)
    {
        if (a <= 1)
        {
            finalPairs = prevPairs = 1;
        }
        else
        {
            newPairs = prevPairs * pairs;

            finalPairs += newPairs;

            prevPairs = finalPairs - newPairs;
        }
    }

    printf("%lld\n", finalPairs);
#elif defined(PROBLEM_5)
    char    dna[2048];
    int     bExtractPercent = 0;
    int     id = 0;
    int     highestID = 0;
    float   fPercent = 0.0f;
    float   fHighestPercent = 0.0f;
    FILE    *pFile = fopen("problem_5_dataset.txt", "r");

    memset(dna, 0, sizeof(dna));

    while (1)
    {
        char line[256];

        if (fgets(line, 256, pFile))
        {
            if (line[0] == '>')
            {
                char *pID = strstr(line, "_");

                if (pID)
                {
                    if (bExtractPercent)
                    {
                        fPercent = extractPercentGC(dna);

                        memset(dna, 0, sizeof(dna));

                        if (fPercent > fHighestPercent)
                        {
                            highestID = id;

                            fHighestPercent = fPercent;
                        }
                    }

                    id = atoi(pID + 1);

                    bExtractPercent = 1;
                }
            }
            else
            {
                strcat(dna, line);
            }
        }
        else
        {
            if (bExtractPercent)
            {
                fPercent = extractPercentGC(dna);

                if (fPercent > fHighestPercent)
                {
                    highestID = id;

                    fHighestPercent = fPercent;
                }
            }

            break;
        }
    }

    fclose(pFile);

    printf("Rosalind_%d\n%f\n", highestID, fHighestPercent);
#elif defined(PROBLEM_6)

#endif

    return 0;
}
