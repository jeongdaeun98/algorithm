//1. hashmap으로 letter당 개수 count
//2. 짝수인 letter count를 answer에 더함
import java.util.*;
class Solution {
    public int longestPalindrome(String s) {
        int answer = 0;
        int secondNum = -1;
        Map<Character, Integer> letterAndCount = new HashMap<>();
        for(int i = 0; i < s.length(); i++) {
            letterAndCount.put(s.charAt(i), letterAndCount.getOrDefault(s.charAt(i), 0) + 1);
        }
        for(Character c : letterAndCount.keySet()) {
            answer += letterAndCount.get(c);
            if(letterAndCount.get(c) % 2 == 1) {
                secondNum++;
            }
        }
        if(secondNum > 0) {
            return answer - secondNum;
        }
        return answer;
    }
}