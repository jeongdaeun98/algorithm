class Solution {
    public boolean canJump(int[] nums) {
        int maxJump = 0;
        int jump = 0;
        for(int i = 0; i < nums.length; i++) {
            if(jump < i) {
                return false;
            }
            maxJump = Math.max(maxJump, i + nums[i]);
            if(jump == i) {
                jump = maxJump;
            }
        }
        return true;
    }
}