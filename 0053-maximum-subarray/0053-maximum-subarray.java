// 1. 순회한다.
// 2. 현재 가리키는 값과 이전의 인덱스에 저장된 값 중 더 큰 값으로 설정
// 3. max sum을 기록
class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0];
        for(int i = 1; i < nums.length; i++) {
            nums[i] = Math.max(nums[i], nums[i] + nums[i - 1]);
            sum = Math.max(sum, nums[i]);
        }
        return sum;
    }
}