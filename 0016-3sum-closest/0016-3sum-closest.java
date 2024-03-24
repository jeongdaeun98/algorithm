// 순회하면서 left와 right의 sum을 저장
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int absMinusNum = Integer.MAX_VALUE, answer = nums[0] + nums[1] + nums[2];
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++) {
            int left = i + 1, right = nums.length - 1;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if(absMinusNum > Math.abs(target - sum)) {
                    answer = sum;
                    absMinusNum = Math.abs(target - sum);
                }
                if(target > sum) {
                    left++;
                } else {
                    right --;
                    
                }
            }
        }
        return answer;
    }
}