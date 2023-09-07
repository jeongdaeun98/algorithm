import java.util.*;
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int sum = 0;
        int total = 0;
        int answer = 0;
        for(int i = 0; i < gas.length; i++) {
            sum += gas[i] - cost[i];
            
            if(sum < 0) {
                total += sum;
                sum = 0;
                answer = i + 1;
            }
        }
        if(total + sum >= 0) {
            return answer;
        } else {
            return -1;
        }
    }
}