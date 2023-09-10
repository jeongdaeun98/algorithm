class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> answers = new ArrayList<>();
        int[] answer = new int[nums.length];
        boolean[] visited = new boolean[nums.length];
        permutation(answer, answers, visited, 0, nums);
        return answers;
    }
    public void permutation(int[] answer, List<List<Integer>> answers, boolean[] visited, int index, int[] nums) {
        if(nums.length == index) {
            answers.add(Arrays.stream(answer).boxed().collect(Collectors.toList()));
            return;
        }
        for(int i = 0; i < nums.length; i++) {
            if(!visited[i]) {
                visited[i] = true;
                answer[index] = nums[i];
                permutation(answer, answers, visited, index + 1, nums);
                visited[i] = false;
            }
        }
    }
}