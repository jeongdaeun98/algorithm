class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int answer = nums[0] + nums[1] + nums[2];
        int minDifference = Math.abs(answer - target);
        for(int i = 0; i < nums.length; i++) {
            int left = i + 1, right = nums.length - 1;
            while(left< right) {
                int sum = nums[left] + nums[i] + nums[right];
                if(Math.abs(sum - target) < minDifference) {
                    answer = sum;
                    minDifference = Math.abs(sum - target);
                }
                if(sum > target) {
                    right --;
                } else {
                    left++;
                }
            }
        }
        return answer;
    }
}