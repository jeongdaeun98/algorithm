//nums.length 만큼 nums 돌면서 없는 수 리턴
class Solution {
    public int missingNumber(int[] nums) {
        Map<Integer, Boolean> numberAndExist = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            numberAndExist.put(nums[i], true);
        }
        for(int i = 0; i <= nums.length; i++) {
            if(!numberAndExist.containsKey(i)) {
                return i;
            }
        }
        return 0;
    }
}