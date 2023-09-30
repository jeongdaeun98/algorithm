class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int count = 0;
        int maxCount = 0;
        int thisNumber = nums[0];
        int majorityElement = 0;
        for(int num : nums) {
    
            if(num != thisNumber) {
                if(maxCount < count) {
                    maxCount = count;
                    majorityElement = thisNumber;
                    count = 0;
                }
                thisNumber = num;
            }
            count++;
        }
        if(maxCount < count) {
            majorityElement = thisNumber;
        }
        return majorityElement;
    }
}