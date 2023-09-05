import java.util.*;
class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> sAndT = new HashMap<>();
        Set<Character> set = new HashSet<>();
        for(int i = 0; i < s.length(); i++) {
            Character sChar = s.charAt(i);
            Character tChar = t.charAt(i);
            if(!sAndT.containsKey(sChar) && !set.contains(tChar)) {
                sAndT.put(sChar, tChar);
                set.add(tChar);
            } else if(set.contains(tChar) && !sAndT.containsKey(sChar) || !sAndT.get(sChar).equals(tChar)) {
                return false;
            }
        }
        return true;
    }
}