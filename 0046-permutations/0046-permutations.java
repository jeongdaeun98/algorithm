class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> answers = new ArrayList<>();
        permutation(nums, answers, 0);
        return answers;
    }
    public void permutation(int[]nums, List<List<Integer>> answers, int start){
        if(start == nums.length) {
            answers.add(Arrays.stream(nums).boxed().collect(Collectors.toList()));
            return;
        }
        for(int i = start; i < nums.length; i++) {
            swap(nums, i, start);
            permutation(nums, answers, start + 1);
            swap(nums, i, start);
        }
    }
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}