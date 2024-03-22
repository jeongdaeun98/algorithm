// jump 만큼 순회
// jump 가장 큰 값으로 갱신
// 순회하면서 인덱스가 nums length와 같은지 체크, 같으면 true
class Solution {
    public boolean canJump(int[] nums) {
        int jump = nums[0];
        int i = 1;
        while(jump > 0) {
            jump--;
            if(i == nums.length) {
                return true;
            }
            jump = Math.max(jump, nums[i]);
            i++;
        }
        if(i == nums.length) {
            return true;
        }
        return false;
    }
}