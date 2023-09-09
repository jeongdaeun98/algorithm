class Solution {
    public int jump(int[] nums) {
        int count = 0;
        int jump = 0;
        int nextJump = 0;
        
        for(int i = 0; i < nums.length - 1; i++) {
            nextJump = Math.max(nextJump, i + nums[i]);
            if(i == jump) {
                count++;
                jump = nextJump;
            }
        }
        return count;
    }
}