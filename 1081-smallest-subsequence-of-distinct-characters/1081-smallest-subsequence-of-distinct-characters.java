import java.util.*;
//1. 가장 마지막 인덱스를 문자열을 순회하면서 기록
//2. 문자열 순회, 문자 값을 스택에 기록, 기록된 문자라면 패스
//3. 현재 인덱스가 마지막 인덱스보다 작고, 인덱스가 가리키는 문자가 최상단의 값보다 작다면 스택에서 뺌
class Solution {
    public String smallestSubsequence(String s) {
        int[] lastIndex = new int[26];
        boolean[] seek = new boolean[26];
        for(int i = 0; i < s.length(); i++) {
            lastIndex[s.charAt(i) - 'a'] = i;
        }
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < s.length(); i++) {
            int ch = s.charAt(i) - 'a';
            if(seek[ch]) {
                continue;
            }
            while(!stack.isEmpty() && i < lastIndex[stack.peek()] && ch < stack.peek()) {
                seek[stack.peek()] = false;
                stack.pop();
            }
            seek[ch] = true;
            stack.push(ch);
        }
        StringBuilder sb = new StringBuilder();
        while(!stack.isEmpty()) {
            sb.append((char)(stack.pop() + 'a'));
        }
        return sb.reverse().toString();
    }
}