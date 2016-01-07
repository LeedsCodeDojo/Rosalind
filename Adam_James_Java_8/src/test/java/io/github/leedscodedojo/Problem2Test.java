package io.github.leedscodedojo;

import org.junit.Test;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.function.Function;

import static java.util.stream.Collectors.counting;
import static java.util.stream.Collectors.groupingBy;
import static org.junit.Assert.*;

public class Problem2Test {
    @Test
    public void testProblem2() throws Exception {
        Problem2 logic = new Problem2();

        assertEquals("GAUGGAACUUGACUACGUAAAUU", logic.problem2("GATGGAACTTGACTACGTAAATT"));
    }

    @Test
    public void solver(){
        Problem2 problem2 = new Problem2();

        System.out.print(problem2.problem2("AGTAGCGGGATCTCGTCTACTAACACCAGTATATACCTGACTAACTTGCCCCCCTAGCACCTCCTTCAAATGCCATATTCATTGTTAGTTAGTGACTTGGGTACGATCCAGACAGCATCTAGCGGCGCGCGAGAGCGGAGGAGGATGCCTACGATCACTCTCTGATGGCGATCATGGGAATTCTGGTCAGCAATGAAGCTCGTTACAAGAGTGTGCCGCTCTGGACGGACCTTTAACACTGGGCTCACCGTTTCTGATCCCCGCGGTTGCTCTGCAGTAGGCTCTGAGGCTCCAAGTAGGTCACGGACTCAGACCACTTATATATGGAAGTAGCTTAGGGCAATAGGGAAGGCACAATTTGCTAAAACCCACCAAAATTAGTACACTGTTGGCGGTTGGCGCCGTCAGACAGGCGGTAACCCCGACGGATGGATTCGATTTTCTCTTGCAAACGGTTGGGTGGCATTGCGGGTAGCCGACGGCGTTTACCAATCCCCTAATGCACACATTTGTATGGGACGGCCGGAGTGGCGCCTGGTGATACACCTTTCGCACGCCGTACGTTGCTGCGCTTTCCGTTCAGCTACTGTTGCCCTCTAAACTATCGCGAAGTGTGATGGCTTGTCAGGAGATCCGTCGAGAGTCCCCTCCATCACTATGCGGAGAAGACGATCCGTGTATACGTATTGGACCTGGTCTCAAGAGCCTTGTGCCGAAAGTTAGCCTGACTTAAAAGAGCCAGTAGAAGACGCTCCACTTTACCTAGCCTCTAACGACGAGCAAAGTTCTTCCGAACAGGCCATTGTTCCAAGGTCTTACACTCCGCGGTTAACGGGCCGATTGACTCGTCTGTGGGTTGTTTTATCGTTCGTTGTGCAACACGCAAGAAACAGTCCTTCAGTTGGCCCAGGTCCCATTTTCCTCGATCAAGAGCAGGAAT\n"));
    }

    @Test
    public void scratch(){
        List<String> wordsList = Arrays.asList("hello", "bye", "ciao", "bye", "ciao");
        Map<String, Long> collect =
                wordsList.stream().collect(groupingBy(Function.identity(), counting()));

        collect.toString();
    }

    @Test
    public void scratch2(){
        List<Character> wordsList = Arrays.asList('A','B','A');
        Map<Character, Long> collect =
                wordsList.stream().collect(groupingBy(Function.identity(), counting()));

        collect.toString();
    }
}