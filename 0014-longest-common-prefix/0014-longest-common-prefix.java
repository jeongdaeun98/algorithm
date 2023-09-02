import java.util.*;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        String answer = "";
        Arrays.sort(strs);
        for(int i = 0; i < strs[0].length(); i++) {
            char str = strs[0].charAt(i);
            boolean same = true;
            for(int j = 0; j < strs.length; j++) {
                if(strs[j].length() <= i || strs[j].charAt(i) != str) {
                    same = false;
                    break;
                }
            }
            if(same){
                answer += str;
            } else {
                break;
            }
        }
        return answer;
    }
}