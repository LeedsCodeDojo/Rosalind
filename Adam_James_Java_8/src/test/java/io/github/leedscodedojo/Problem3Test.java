package io.github.leedscodedojo;

import org.junit.Test;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.function.Function;

import static java.util.stream.Collectors.counting;
import static java.util.stream.Collectors.groupingBy;
import static org.junit.Assert.assertEquals;

public class Problem3Test {
    @Test
    public void testProblem2() throws Exception {
        Problem3 logic = new Problem3();

        assertEquals("TGAC", logic.execute("GTCA"));
        assertEquals("AAAACCCGGT", logic.execute("ACCGGGTTTT"));
    }
}