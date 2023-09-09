class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> parenthesis = new ArrayList<>();
        generate(parenthesis, n, n, "");
        return parenthesis;
    }
    public void generate(List<String> parenthesis, int left, int right, String parenthese) {
        if(left == 0 && right == 0) {
            parenthesis.add(parenthese);
            return;
        }
        if(left > 0) {
            generate(parenthesis, left - 1, right, parenthese + "(");
        } 
        if(left < right) {
            generate(parenthesis, left, right - 1, parenthese + ")");
        }
    }
}