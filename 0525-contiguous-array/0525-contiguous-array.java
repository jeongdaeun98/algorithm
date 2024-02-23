// 0 1 0 1
// -1 1 -1 1 가정
// -1 0 -1 0  sum이 같을 경우 인덱스 가장 작은 거 - 순회 인덱스가 subArray의 길이
// 가장 큰 subArray 길이로 설정
class Solution {
    public int findMaxLength(int[] nums) {
        int sum = 0;
        int answer = 0;
        Map<Integer,Integer> sumAndCount = new HashMap<>();
        sumAndCount.put(0, -1);
        for(int i = 0; i < nums.length; i++) {
            sum += nums[i] * 2 - 1;
            if(sumAndCount.containsKey(sum)) {
                answer= Math.max(answer, i - sumAndCount.get(sum));
            } else {
                sumAndCount.put(sum, i);
            }
        }
        return answer;
    }
}