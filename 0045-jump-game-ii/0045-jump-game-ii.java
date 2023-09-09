class Solution {
    public int jump(int[] nums) {
        int changeCount = 0;
        int interval = 0;
        int newInterval = 0;
        for(int i = 0; i < nums.length - 1; i++) {
            newInterval = Math.max(newInterval, nums[i] + i);
            if(i == interval) {
                changeCount++;
                interval = newInterval;
            }
        }
        return changeCount;
    }
}