class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> answers = new ArrayList<>();
        permutation(answers, nums, 0, nums.length);
        return answers;
    }
    
    public void permutation(List<List<Integer>> answers, int[] nums, int start, int end) {
        if(start == nums.length) {
            answers.add(Arrays.stream(nums).boxed().collect(Collectors.toList()));
            return;
        }
        for(int i = start; i < end; i++) {
            swap(nums, start, i);
            permutation(answers, nums, start + 1 , end);
            swap(nums, start, i);
        }
    }
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}