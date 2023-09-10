class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> answers = new ArrayList<>();
        LinkedList<Integer> answer = new LinkedList<>();
        combination(answer, answers, n, k, 1);
        return answers;
    }
    public void combination(LinkedList<Integer> answer, List<List<Integer>> answers, int n, int k, int index) {
        if(answer.size() == k) {
            answers.add(new ArrayList<>(answer));
            return;
        }
        if(index > n) {
            return;
        }
        answer.add(index);
        combination(answer, answers, n, k, index + 1);
        answer.removeLast();
        combination(answer, answers, n, k, index + 1);
    }
}