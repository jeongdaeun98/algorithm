// 0은 -1로 치환
// 누적해서 합해가다가 동일한 합이 나오면 첫번째 나온 인덱스와 빼준다.
// 그중 가장 큰 값을 answer로 리턴
import java.util.*;
class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> prefixAndIndex = new HashMap<>();
        int answer = 0;
        int sum = 0;
        prefixAndIndex.put(0,-1);
        for(int i = 0; i < nums.length; i++) {
            nums[i] = nums[i] * 2 - 1;
            sum += nums[i];
            if(prefixAndIndex.containsKey(sum)) {
                answer = Math.max(answer, i - prefixAndIndex.get(sum));
            } else {
                prefixAndIndex.put(sum, i);
            }
        }
        return answer;
    }
}