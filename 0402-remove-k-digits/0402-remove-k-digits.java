// 1. num 스트링에 대해서 앞에서부터 차례대로 스택에 넣는데, 만일 스택에 들어간 값보다 작으면, 스택에 들어간 값을 빼고 k를 빼준다.
// 2. 순회가 끝나면, 값이 같아서 빠지지 않았던 케이스를 고려하여, k가 0이 될 때까지 stack에서 뺀다.
// 3. stack에 있는 값을 string으로 변환
// 4. 맨 앞에 있는 값이 0일 경우, string 값에서 뺀 후 리턴.
import java.util.*;
class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Integer> stack = new Stack<>(); 
        for(int i = 0; i < num.length(); i++) {
            while(!stack.isEmpty() && stack.peek() > num.charAt(i) - '0' && k > 0) {
                stack.pop();
                k--;
            }
            stack.push(num.charAt(i) - '0');
        }
        while(k > 0) {
            stack.pop();
            k--;
        }
        StringBuilder sb = new StringBuilder();
        while(!stack.isEmpty()) {
            sb.append(Integer.toString(stack.pop()));
        }
        sb = sb.reverse();
        while(sb.length() > 1 && sb.charAt(0) == '0') {
            sb.deleteCharAt(0);
        }
        if(sb.length() == 0) {
            return "0";
        }
        return sb.toString();
    }
}