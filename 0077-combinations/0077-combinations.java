class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> answers = new ArrayList<>();
        LinkedList<Integer> answer = new LinkedList<>();
        combination(answers, answer, 1, k, n);
        return answers;
    }
    public void combination(List<List<Integer>> answers, LinkedList<Integer> answer, int index, int k, int n) {
        if(answer.size() == k) {
            answers.add(new ArrayList<>(answer));
            return;
        }
        if(index > n) {
            return;
        }
        combination(answers, answer, index + 1, k, n);
        answer.add(index);
        combination(answers, answer, index + 1, k, n);
        answer.removeLast();
    }
}