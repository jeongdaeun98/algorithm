import java.util.*;
class Solution {
    public int removeDuplicates(int[] nums) {
        int answer = nums.length;
        int index = 1;
        for(int i = 0; i < nums.length - 1; i++) {
            if(nums[i] != nums[i+1]) {
                nums[index++] = nums[i + 1];
            } else {
                answer--;
            }
        }
        return answer;
    }
}