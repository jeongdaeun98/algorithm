import java.util.*;
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> duplicateNums = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            if(duplicateNums.containsKey(nums[i])) {
                if(Math.abs(duplicateNums.get(nums[i]) - i) <= k) {
                    return true;
                }
            } 
            duplicateNums.put(nums[i], i);
        }
        return false;
    }
}