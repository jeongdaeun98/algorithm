// 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1
// 0 0 1 1 0 0 1 1 1 0 1 1 1 1 1 1 1 1 1
class Solution {
    public int longestOnes(int[] nums, int k) {
        int end = 0, start = 0, zeros = 0;
        while(end < nums.length) {
            if(nums[end++] == 0) {
                zeros++;
            }
            if(zeros > k) {
                if(nums[start] == 0) {
                    zeros--;
                }
                start++;
            }
        }
        return end - start;
    }
}