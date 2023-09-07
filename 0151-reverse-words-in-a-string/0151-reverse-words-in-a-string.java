import java.util.*;
class Solution {
    public String reverseWords(String s) {
        String answer = "";
        s = s.trim();
        s = s.replaceAll("\\s+", " ");
        String[] splitWords = s.split(" ");
        for(int i = splitWords.length - 1; i >= 0; i--) {
            answer += splitWords[i];
            if(i != 0) {
                answer += " ";
            }
        }
        return answer;
    }
}