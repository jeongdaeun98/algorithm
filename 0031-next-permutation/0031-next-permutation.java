class Solution {
    public void nextPermutation(int[] nums) {
        int lastIndex = nums.length - 1;
        boolean isNext = false;
        for(int i = lastIndex; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                isNext = true;
                for(int j = lastIndex; j >= i; j--) {
                    if(nums[i - 1] < nums[j]) {
                        swap(i - 1,nums, j);
                        break;
                    }
                }
                int[] copiedArray = Arrays.copyOfRange(nums, i, lastIndex + 1);
                Arrays.sort(copiedArray);
                replace(i, copiedArray, nums);
                break;
            }
        }
        if(!isNext) {
            Arrays.sort(nums);
        }
    }
    public void swap(int index, int[] nums, int changeIndex) {
        int temp = nums[changeIndex];
        nums[changeIndex] = nums[index];
        nums[index] = temp;
    }
    public void replace(int index, int[] copiedArray, int[]nums) {
        for(int i = 0; i < copiedArray.length; i++) {
            nums[index + i] = copiedArray[i];
        }
    }
}