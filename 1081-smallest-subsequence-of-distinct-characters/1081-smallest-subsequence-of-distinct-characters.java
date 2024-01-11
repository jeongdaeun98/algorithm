//1. 알파벳 별 마지막 인덱스를 설정
//2. 순회하면서 스택에 알파벳을 넣는데, 순회 인덱스가 스택 알파벳의 마지막 인덱스보다 작고, 순회 알파벳이 스택 알파벳보다 작을 경우 스택 빼고 방문 표시 안함으로 설정
//3. 스택에 데이터 reverse 후 리턴
class Solution {
    public String smallestSubsequence(String s) {
        int lastIndex[] = new int[26];
        boolean seek[] = new boolean[26];
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
                seek[stack.pop()] = false;
            }
            stack.push(ch);
            seek[ch] = true;
        }
        StringBuilder sb = new StringBuilder();
        while(!stack.isEmpty()) {
            sb.append((char)(stack.pop() + 'a'));
        }
        return sb.reverse().toString();
    }
}