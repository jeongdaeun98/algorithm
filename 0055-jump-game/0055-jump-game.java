// 순회한다.
// 순회하면서 range 끝까지 도달했을 때, 최대 range 마지막 인덱스로 변경한다.
// 그 인덱스가 마지막 인덱스보다 크거나 같다면 true 리턴
class Solution {
    public boolean canJump(int[] nums) {
        int interval = nums[0];
        int maxInterval = 0;
        for(int i = 0; i < nums.length; i++) {
            maxInterval = Math.max(maxInterval, i + nums[i]);
            if(interval == i) {
                interval = maxInterval;
            }
            if(interval >= nums.length - 1) {
                return true;
            }
        }
        return false;
    }
}