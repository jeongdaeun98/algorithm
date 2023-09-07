import java.util.*;
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int answer = nums.length;
        boolean possible = false;
        int end = 0;
        int start = 0;
        int sum = 0;
        while(end < nums.length) {
            sum += nums[end++];
            while(start < nums.length && sum >= target){
                possible = true;
                answer = Math.min(answer, end - start);
                sum -= nums[start++];
            }
        }
        if(possible){
            return answer;
        } else {
            return 0;
        }
    }
}