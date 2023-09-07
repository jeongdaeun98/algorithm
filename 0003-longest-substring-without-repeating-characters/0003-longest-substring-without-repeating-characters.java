import java.util.Set;
import java.util.HashSet;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int answer = 0;
        String string = "";
        for(int i = 0; i < s.length(); i++) {
            String element = Character.toString(s.charAt(i));
            if(string.contains(element)) {
                answer = Math.max(string.length(), answer);
                string = string.substring(string.indexOf(element) + 1);
            }
            string += element;
        }
        return Math.max(answer, string.length());
    }
}