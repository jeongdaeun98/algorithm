import java.util.*;
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<String, Integer> charCounts = new HashMap<>();
        for(int i = 0; i < magazine.length(); i++) {
            String spell = Character.toString(magazine.charAt(i));
            if(charCounts.containsKey(spell)){
                charCounts.put(spell, charCounts.get(spell) + 1);
            } else {
                charCounts.put(spell, 1);
            }
        }
        for(int i = 0 ; i < ransomNote.length(); i++) {
            String spell = Character.toString(ransomNote.charAt(i));
            if(charCounts.containsKey(spell) && charCounts.get(spell) > 0) {
                charCounts.put(spell, charCounts.get(spell) - 1);
            } else {
                return false;
            }
        }
        return true;
    }
}