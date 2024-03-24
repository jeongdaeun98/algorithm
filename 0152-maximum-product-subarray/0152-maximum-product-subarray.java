// 
class Solution {
    public int maxProduct(int[] nums) {
        int answer = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length; i++) {
            int mul = nums[i];
            for(int j = i + 1; j < nums.length; j++) {
                answer = Math.max(answer, mul);
                mul *= nums[j];
            }
            answer = Math.max(answer, mul);
        }
        return answer;
    }
}