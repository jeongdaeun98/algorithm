// 순회
// 가장 작은 값 i로 갱신
// i보다 큰 값 j 갱신
// j보다 크고 i보다 큰 값 k로 갱신
import java.util.*;
class Solution {
    public boolean increasingTriplet(int[] nums) {
        int i = Integer.MAX_VALUE, j = i, k = i;
        boolean ip = false, jp = false, kp = false;
        for(int index = 0; index < nums.length; index++) {
            if(i >= nums[index]) {
                i = nums[index];
                ip = true;
            } else if(j >= nums[index]) {
                j = nums[index];
                jp = true;
            } else if(k >= nums[index]) {
                k = nums[index];
                kp = true;
            }
        }
        if(ip && jp && kp) {
            return true;
        }
        return false;
    }
}