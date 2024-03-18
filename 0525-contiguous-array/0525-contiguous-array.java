// -1 1 -1 1 -1 1
// -1 0 -1 0 -1 0
// 0. 1. 2 3 4. 5
// -1 -1 1 1 -1 -1
// -1 -2 -1 0 -1 -2
class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> sumAndIndex = new HashMap<>();
        sumAndIndex.put(0, -1);
        int sum = 0, answer = 0;
        for(int i = 0; i < nums.length; i++) {
            sum += nums[i] * 2 - 1;
            if(sumAndIndex.containsKey(sum)){
                answer = Math.max(answer, i - sumAndIndex.get(sum));
            } else {
                sumAndIndex.put(sum, i);
            }
        }
        return answer;
    }
}