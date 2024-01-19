// 자신으로부터 앞에 인덱스를 더한 것과 자신 중 가장 큰 것을 dp 에 저장.
// 가장 큰 값 answer로 리턴
class Solution {
    public int maxSubArray(int[] nums) {
        int[] dp = new int[nums.length];
        int answer = nums[0];
        dp[0] = nums[0];
        for(int i = 1; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 1] + nums[i], nums[i]);
            answer = Math.max(answer, dp[i]);
        }
        return answer;
    }
}