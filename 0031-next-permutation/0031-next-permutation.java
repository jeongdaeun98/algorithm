class Solution {
    public void nextPermutation(int[] nums) {
        boolean isNext = false;
        for(int i = nums.length - 1; i >= 1; i--) {
            if(i - 1 >= 0 && nums[i - 1] < nums[i]){
                isNext = true;
                for(int j = nums.length - 1; j >= i; j--) {
                    if(nums[i - 1] < nums[j]) {
                        swap(i - 1, j, nums);
                        break;
                    }
                }
                int[] copyNums = Arrays.copyOfRange(nums,i, nums.length);
                Arrays.sort(copyNums);
                replaceArray(nums, copyNums, i, nums.length);
                break;
            }
    }
        if(!isNext) {
            Arrays.sort(nums);
        }
    }
    public void swap(int i, int j, int[] nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public void replaceArray(int[] nums, int[] copyNums, int start, int end) {
        for(int i = start; i < end; i++) {
            nums[i] = copyNums[i - start];
        }
    }
}