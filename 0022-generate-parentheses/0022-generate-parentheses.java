// 1. permutation으로 구현, left와 right를 n으로 요청
// 2. right는 left보다 클 때만 추가되도록 함.
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> answers = new ArrayList<>();
        permutation(n, n, answers, "");
        return answers;
    }
    public void permutation(int left, int right, List<String> answers, String answer) {
        if(left == 0 && right == 0) {
            answers.add(answer);
            return;
        }
        if((left < 0 || right < 0) ||(left > right)) {
            return;
        }
        if(left > 0) {
            permutation(left - 1, right, answers, answer + "(");
        } 
        permutation(left, right - 1, answers, answer + ")");
    }
}