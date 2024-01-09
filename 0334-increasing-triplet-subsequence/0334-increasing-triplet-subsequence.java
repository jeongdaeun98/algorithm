// 1. 순회
// 2. i 가장 작은 값
// 3. 순회할 때마다 가장 작은 값보다 더 작은지 확인, 더 작으면 i 갱신 후 j와 k를 null로 갱신
// 4. 더 작지는 않으면, j보다 더 작은지 확인, 그러면 j를 갱신
// 5. i보다 작지는 않고, j보다 작으면 j를 갱신
// 6. 마지막에서 i,j,k가 null이 아니라면 true 리턴
class Solution {
    public boolean increasingTriplet(int[] nums) {
        int i = Integer.MAX_VALUE, j = Integer.MAX_VALUE;
        for(int index = 0; index < nums.length; index++) {
            if(i >= nums[index]) {
                i = nums[index];
            } else if(j >= nums[index]) {
                j = nums[index];
            } else {
                return true;
            }
        }
        return false;
    }
}