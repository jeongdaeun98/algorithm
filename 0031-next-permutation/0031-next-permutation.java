class Solution {
    public void nextPermutation(int[] nums) {
        int index = 0;
        boolean isNext = false;
        for(int i = nums.length - 1; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                index = i - 1;
                isNext = true;
                break;
            }
        }
        if(!isNext) {
            Arrays.sort(nums);
            return;
        }
        for(int i = nums.length - 1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(i, index, nums);
                break;
            }
        }
        int[] copy = Arrays.copyOfRange(nums, index + 1, nums.length);
        Arrays.sort(copy);
        replace(nums, copy, index + 1);
    }
    public void swap(int i, int j, int[] nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public void replace(int[] nums, int[] copy, int index) {
        for(int i = 0; i < copy.length; i++) {
            nums[index + i] = copy[i];
        }
    }
}