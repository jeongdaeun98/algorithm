import java.util.*;
class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> letters = new HashMap<>();
        for(int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            if(!letters.containsKey(c)){
                letters.put(c, 1);
            } else {
                letters.put(c, letters.get(c) + 1);
            }
        }
        for(int i = 0; i < t.length(); i++) {
            Character c = t.charAt(i);
            if(letters.containsKey(c) && letters.get(c) > 0) {
                letters.put(c, letters.get(c) - 1);
            } else {
                return false;
            }
        }
        for(Character letter : letters.keySet()) {
            if(letters.get(letter) > 0) {
                return false;
            }
        }
        return true;
    }
}