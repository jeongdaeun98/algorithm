import java.util.*;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> answer = new ArrayList<>();
        generate(n - 1, n, "(", answer);
        return answer;
    }
    
    public void generate(int open, int close, String bracket, List<String> answer) {
        if(open == 0 && close == 0) {
            answer.add(bracket);
            return;
        }
        
        if(open < close) {
            generate(open, close - 1, bracket + ")", answer);
        }
        if(open > 0) {
            generate(open - 1, close, bracket + "(", answer);
        }
    }
}