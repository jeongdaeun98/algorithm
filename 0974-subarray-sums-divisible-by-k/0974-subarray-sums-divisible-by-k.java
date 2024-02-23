// 누적합
// 누적합을 구한 후, subarray는 sum[i] - sum[j]로 구할 수 있음
// (sum[i] - sum[j]) % k == 0
// sum[i] % k == sum[j] % k 인 것을 고르면 되고 O(n)으로 구할 수 있다.
// 순회하면서
// 나머지가 같은 게 있을 때, 누적된 array 개수를 answer에 더해준다. (부분 배열이라고 했을 때, 해당 수를 추가해서 새로운 array를 만들 수 있으니까)
import java.util.*;
class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int sum = 0;
        int answer = 0;
        Map<Integer, Integer> sumAndCount = new HashMap<>();
        sumAndCount.put(0,1);
        for(int i = 0; i < nums.length; i++) {
            sum += nums[i];
            int remainder = (sum % k + k) % k;
            if(sumAndCount.containsKey(remainder)) {
                answer += sumAndCount.get(remainder);
                sumAndCount.put(remainder, sumAndCount.get(remainder) + 1);
            } else {
                sumAndCount.put(remainder, 1);
            }
        }
        return answer;
    }
}