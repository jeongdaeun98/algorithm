// 누적합
// 합을 누적해서 저장하면, 계속 누적하는 것과 1,2,3,4가 있다고 했을 때, 1번은 제외하고 2~4까지 더하는 방식이 있다.
// 후자의 경우, k로 나누어서 나머지가 남았을 때 그 나머지만큼을 뺄 수 있다면 good subarray로 취급 됨
// 1번의 나머지와 저장한 수의 나머지가 같은 경우, 1번을 빼면 good subarray임.
import java.util.*;
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int sum = 0;
        Map<Integer, Integer> remainders = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            sum += nums[i];
            sum %= k;
            if(remainders.containsKey(sum) && i - remainders.get(sum) > 1) {
                return true;
            }
            if(sum == 0 && i > 0) {
                return true;
            }
            if(!remainders.containsKey(sum)) {
                remainders.put(sum, i);
            }
        }
        return false;
    }
}