package io.github.leedscodedojo;

import java.util.Map;
import java.util.stream.Collectors;

import static io.github.leedscodedojo.Problem2.toList;
import static java.util.function.Function.identity;

public class Problem1 {
    public String execute(String in) {
        Map<Character, Long> results =
                toList(in).stream()
                        .collect(Collectors.groupingBy(identity(), Collectors.counting()));

        return String.format("%d %d %d %d", results.get('A'), results.get('C'), results.get('G'), results.get('T'));
    }
}
