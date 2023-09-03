import java.util.*;
class Solution {
    public int removeDuplicates(int[] nums) {
        boolean isDuplicated = false;
        int index = 1;
        int answer = nums.length;

        for(int i = 0; i < nums.length - 1; i++) {
            if(nums[i] != nums[i + 1]) {
                nums[index++] = nums[i + 1];
                isDuplicated = false;
             }
            else if(!isDuplicated && nums[i] == nums[i + 1]) {
                isDuplicated = true;
                nums[index++] = nums[i + 1];
            } else {
                answer--;
            }
        }
        return answer;
    }
}