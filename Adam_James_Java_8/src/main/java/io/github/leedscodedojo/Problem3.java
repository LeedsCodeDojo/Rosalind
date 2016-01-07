package io.github.leedscodedojo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Collectors;

import static io.github.leedscodedojo.Problem2.toList;

public class Problem3 {
    public String execute(String in) {
        ArrayList<Character> characters = toList(in);
        Collections.reverse(characters);

        return characters
                .stream()
                .map(Problem3::mapper)
                .map(Object::toString)
                .collect(Collectors.joining());
    }

    public static Character mapper(Character c){
        switch (c){
            case 'A': return 'T';
            case 'T': return 'A';
            case 'C': return 'G';
            case 'G': return 'C';
            default: return c;
        }
    }
}
