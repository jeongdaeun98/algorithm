import java.util.*;
class Solution {

public boolean isPossible(int[] nums) {
        Map<Integer,Integer> availability = new HashMap<>();
        Map<Integer,Integer> possibility = new HashMap<>();
        for(int num : nums){
            availability.put(num,availability.getOrDefault(num,0)+1);
        }
        for(int num:nums){
            if(availability.get(num)==0)continue;
            if(possibility.getOrDefault(num,0)>0){
                possibility.put(num,possibility.getOrDefault(num,0)-1);
                possibility.put(num+1,possibility.getOrDefault(num+1,0)+1);
            }
            else if(availability.getOrDefault(num+1,0)>0 && availability.getOrDefault(num+2,0)>0 ){
                possibility.put(num+3,possibility.getOrDefault(num+3,0)+1);
                availability.put(num+1,availability.getOrDefault(num+1,0)-1);
                availability.put(num+2,availability.getOrDefault(num+2,0)-1);
            }
            else{
                return false;
            }
            availability.put(num,availability.get(num)-1);
        }
        return true;
}
}