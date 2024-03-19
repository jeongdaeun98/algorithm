// 순회
// sum 더해가기
// sum에 대해 기록
// 현재 순회하는 sum과 이전 순회 sum을 빼면 순회 인덱스에서 이전 순회 인덱스 범위의 sum이 구해짐
// sum - k = x라면, sum - sum + k = k 이므로, sum-k인 애가 존재한다면 그 개수만큼 answer로 더해줌
class Solution {
    public int subarraySum(int[] nums, int k) {
        int answer = 0, sum = 0;
        Map<Integer, Integer> sumAndCount = new HashMap<>();
        sumAndCount.put(0, 1);
        for(int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if(sumAndCount.containsKey(sum - k)) {
                answer += sumAndCount.get(sum - k);
            }
            sumAndCount.put(sum, sumAndCount.getOrDefault(sum, 0) + 1);
        }
        return answer;
    }
}