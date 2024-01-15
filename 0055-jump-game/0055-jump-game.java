// 1. 인덱스 이동 시, 현 jump랑 과거에 가장 큰 Jumpr값 중 가장 큰 jump 값으로 갱신
// 2. 이동할 때마다 감소
// 3. 마지막 이동했을 때 0보다 크거나 같으면 true 리턴
class Solution {
    public boolean canJump(int[] nums) {
        int jump = nums[0];
        if(nums.length == 1) {
            return true;
        }
        for(int i = 1; i < nums.length - 1; i++) {
            jump--;
            if(jump >= 0) {
                jump = Math.max(jump, nums[i]);
            } else {
                return false;
            }
        }
        if(jump <= 0) {
            return false;
        }
        return true;
    }
}