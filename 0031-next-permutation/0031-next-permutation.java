class Solution {
    public void nextPermutation(int[] nums) {
        boolean isNext = false;
        int index = 0;
        for(int i = nums.length - 1; i > 0; i--) {
            if(nums[i] > nums[i - 1]) {
                isNext = true;
                index = i - 1;
                break;
            }
        }
        if(!isNext) {
            Arrays.sort(nums);
            return;
        }
        for(int j = nums.length - 1; j > index; j--) {
            System.out.println(nums[index]);
            if(nums[index] < nums[j]) {
                swap(nums, index, j);
                break;
            }
        }
        int[] copy = Arrays.copyOfRange(nums, index + 1, nums.length);
        Arrays.sort(copy);
        replace(index + 1, nums, copy);
    }
    public void swap(int[] nums, int i, int j ){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    public void replace(int index, int[]nums, int[] copy) {
        for(int i = 0; i < copy.length; i++) {
            nums[i + index] = copy[i]; 
        }
    }
}