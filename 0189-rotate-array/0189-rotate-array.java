import java.util.*;
class Solution {
    public void rotate(int[] nums, int k) {
        List<List<Integer>> numberIndexes = new ArrayList<>();
        int length = nums.length;
        for (int i = 0; i < length; i++)  {
            numberIndexes.add(new ArrayList<>());
        }

        for(int i = 0; i < nums.length; i++) {
            List<Integer> indexes = numberIndexes.get(i);
            indexes.add(nums[i]);
            int num = i + k;
            indexes.add(num % length);
        }
        for(int i = 0; i < nums.length; i++) {
            List<Integer> indexes = numberIndexes.get(i);
            nums[indexes.get(1)] = indexes.get(0); 
        }
    }
}