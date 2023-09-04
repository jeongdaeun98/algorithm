import java.util.*;
class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ranges = new ArrayList<>();
        String range = "";
        for(int i = 0; i < nums.length - 1; i++) {
            if(nums[i] + 1 != nums[i + 1]) {
                range += Integer.toString(nums[i]);
                ranges.add(range);
                range = "";
            } else if(range.equals("")) {
                range += Integer.toString(nums[i]) + "->";
            }
        }
        if(nums.length > 0){
            range += Integer.toString(nums[nums.length - 1]);
            ranges.add(range);
        }
        return ranges;
    }
}