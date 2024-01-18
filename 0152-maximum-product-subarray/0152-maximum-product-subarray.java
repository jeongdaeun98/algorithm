// 순회하면서
// 순회하는 인덱스보다 큰 인덱스들을 순회하면서 계속 곱해가면서 가장 큰 값을 저장
// 
class Solution {
    public int maxProduct(int[] nums) {
        int result = nums[0];
        for(int i = 0; i < nums.length; i++) {
            int mul = nums[i];
            for(int j = i + 1; j < nums.length; j++) {
                result = Math.max(result, mul);
                mul *= nums[j];
            }
            result = Math.max(result, mul);
        }
        return result;
    }
}