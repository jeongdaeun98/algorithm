class Solution {
    public int pivotIndex(int[] nums) {
        int[] leftSum = new int[nums.length];
        int[] rightSum = new int[nums.length];
        leftSum[0] = nums[0];
        rightSum[nums.length - 1] = nums[nums.length - 1];
        for(int i = 1; i < nums.length; i++) {
            int right = nums.length - 1 - i;
            leftSum[i] += nums[i] + leftSum[i - 1];
            rightSum[right] += nums[right] + rightSum[right + 1];
        }
        for(int i = 0; i < nums.length; i++) {
            if(leftSum[i] == rightSum[i]) {
                return i;
            }
        }
        return -1;
    }
}