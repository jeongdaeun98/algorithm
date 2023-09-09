import java.util.*;
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> answers = new ArrayList<>();
        LinkedList<Integer> answer = new LinkedList<>();
        combination(candidates, answer, answers, target, 0);
        return answers;
    }
    
    public void combination(int[] candidates, LinkedList<Integer> answer, List<List<Integer>> answers, int target, int index){
        if(target == 0) {
            answers.add(new ArrayList<Integer>(answer));
            return;
        }
        if(target < 0 || index >= candidates.length) {
            return;
        }
        answer.add(candidates[index]);
        combination(candidates, answer, answers, target - candidates[index], index);
        answer.removeLast();
        combination(candidates, answer, answers, target, index + 1);
    }
}