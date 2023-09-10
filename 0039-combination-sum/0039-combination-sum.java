class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        LinkedList<Integer> answer = new LinkedList<>();
        List<List<Integer>> answers = new ArrayList<>();
        combination(candidates, answers, answer, target, 0, 0);
        return answers;
    }
    
    public void combination(int[] candidates, List<List<Integer>> answers, LinkedList<Integer> answer, int target, int sum, int index) {
        if(sum == target) {
            answers.add(new ArrayList<>(answer));
            return;
        }
        if(sum > target) {
            return;
        }
        if(answer.size() == 150) {
            return;
        }
        if(index == candidates.length) {
            return;
        }
        
        answer.add(candidates[index]);
        combination(candidates, answers, answer, target, sum + candidates[index], index);
        answer.removeLast();
        combination(candidates, answers, answer, target, sum, index + 1);
    }
}