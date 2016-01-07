package io.github.leedscodedojo;

import java.util.ArrayList;
import java.util.stream.Collectors;

public class Problem2 {
    public String problem2(String in) {
        ArrayList<Character> chars = toList(in);
        return chars
                .stream()
                .map(c -> c=='T'?'U':c)
                .map(Object::toString)
                .collect(Collectors.joining());
    }

    public static ArrayList<Character> toList(String array){
        ArrayList<Character> characters = new ArrayList<>();
        for(Character c : array.toCharArray()){
            characters.add(c);
        }
        return characters;
    }
}
