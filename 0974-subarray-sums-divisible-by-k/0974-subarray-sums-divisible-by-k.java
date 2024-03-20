// 누적합
// sum % k == sum1 % k
// 3 % 2 == 1 % 2
// sum과 sum1을 빼면 k의 배수라는 뜻이므로.
class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        Map<Integer, Integer> sumAndCount = new HashMap<>();
        int sum = 0, answer = 0;
        sumAndCount.put(0, 1);
        for(int i = 0; i < nums.length; i++) {
            sum += nums[i];
            int remainder = (sum % k + k) % k; // 양수로 계산되도록
            if(sumAndCount.containsKey(remainder)) {
                answer += sumAndCount.get(remainder);
            }
            sumAndCount.put(remainder, sumAndCount.getOrDefault(remainder, 0) + 1);
        }
        return answer;
    }
}