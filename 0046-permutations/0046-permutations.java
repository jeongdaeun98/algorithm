class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> answers = new ArrayList<>();
        LinkedList<Integer> answer = new LinkedList<>();
        boolean[] visit = new boolean[nums.length];
        Arrays.fill(visit, false);
        permutation(answers, answer, nums, visit);
        return answers;
    }
    public void permutation(List<List<Integer>>answers, LinkedList<Integer> answer, int[]nums,boolean[]visit) {
        if(answer.size() == nums.length) {
            answers.add(new ArrayList<>(answer));
            return;
        }
        
        for(int i = 0; i < nums.length; i++) {
            if(visit[i]){
                continue;
            }
            visit[i] = true;
            answer.add(nums[i]);
            permutation(answers, answer, nums, visit);
            answer.removeLast();
            visit[i] = false;
        }
    }
}