// -2 1 -3 4 -1 2 1 -5 4
// -1 1  
class Solution {
    public int maxSubArray(int[] nums) {
        int maxNum = nums[0];
        for(int i = 1; i < nums.length; i++) {
           nums[i] = Math.max(nums[i], nums[i] + nums[i - 1]); 
            maxNum = Math.max(maxNum, nums[i]);
        }
        return maxNum;
    }
}