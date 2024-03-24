// 순회
// 다음 수부터 순회하면서 곱한 값 중 가장 큰 값으로 갱신
class Solution {
    public int maxProduct(int[] nums) {
        int maxNum = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length; i++) {
            int mul = nums[i];
            for(int j = i + 1; j < nums.length; j++) {
                maxNum = Math.max(maxNum, mul);
                mul *= nums[j];
            }
            maxNum = Math.max(maxNum, mul);
        }
        return maxNum;
    }
}