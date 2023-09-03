import java.util.*;

class Solution {
    public int majorityElement(int[] nums) {
        int answer = 0;
        int maxCount = 0;
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for(int i = 0 ; i < nums.length; i++) {
            if(!frequencyMap.containsKey(nums[i])){
                frequencyMap.put(nums[i], 1);
            } else {
                frequencyMap.put(nums[i], frequencyMap.get(nums[i]) + 1);
            }
        }  
        
        for (Integer key : frequencyMap.keySet()) {
            if(maxCount < frequencyMap.get(key)) {
                answer = key;
                maxCount = frequencyMap.get(key);
            }
        }
        return answer;
    }
}