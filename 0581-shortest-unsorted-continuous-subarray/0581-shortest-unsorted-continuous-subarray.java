// 투포인터로 정렬이 되지 않은 인덱스를 찾기
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int n = nums.length - 1;
        int max = nums[0], min = nums[n];
        int answerLeft = -2, answerRight = -1;
        for(int i = 1; i < nums.length; i++) {
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[n - i]);
            if(nums[i] < max) {
                answerLeft = i;
            }
            if(nums[n -i] > min) {
                answerRight = n - i;
            }
        }
        return answerLeft - answerRight + 1;
    }
}