import java.util.*;
//1. s 문자열의 알파벳의 마지막 인덱스를 기록해둔다.
//2. 문자열의 알파벳 별로 기록했음을 표기한다.
//3. 문자열을 순회하면서, 기록된 알파벳은 패스한다.
//4. 스택에 문자열을 넣는데, 만일 스택 앞단에 데이터를 뽑았을 때, 순회 문자보다 크고, 마지막 인덱스보다 작을 경우 스택에서 빼내고, 기록되지 않았음을 표기한다.
// 5. 순회가 완료되면, 스택에 기록된 문자열을 모두 빼내서 reverse해서 리턴한다.
class Solution {
    public String removeDuplicateLetters(String s) {
        boolean seek[] = new boolean[26];
        int lastIndex[] = new int[26];
        for(int i = 0; i < s.length(); i++) {
            lastIndex[s.charAt(i) - 'a'] = i;
        }
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < s.length(); i++) {
            int ch = s.charAt(i) - 'a';
            if(seek[ch]) {
                continue;
            }
            while(!stack.isEmpty() && lastIndex[stack.peek()] > i && ch < stack.peek()) {
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