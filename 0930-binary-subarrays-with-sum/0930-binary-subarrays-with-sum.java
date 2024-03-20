class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        Map<Integer, Integer> sumAndCount = new HashMap<>();
        sumAndCount.put(0, 1);
        int sum = 0, answer= 0;
        for(int i = 0; i <nums.length; i++) {
            sum += nums[i];
            if(sumAndCount.containsKey(sum - goal)) {
                answer += sumAndCount.get(sum - goal);
            }
            sumAndCount.put(sum, sumAndCount.getOrDefault(sum, 0) + 1);
        }
        return answer;
    }
}