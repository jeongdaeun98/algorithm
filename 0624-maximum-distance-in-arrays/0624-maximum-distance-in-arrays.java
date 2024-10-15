// min max 찾아서 distance 구함
//[[1,5],[3,4]]
import java.util.*;
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int minNum = Integer.MAX_VALUE;
        int minIndex = 0; int maxIndex = 0;
        int maxNum = Integer.MIN_VALUE;
        int twoMinNum = Integer.MAX_VALUE;
        int twoMaxNum = Integer.MIN_VALUE;
        for(int i = 0; i < arrays.size(); i++) {
            if(minNum > arrays.get(i).get(0)) {
                twoMinNum = minNum;
                minNum = arrays.get(i).get(0);
                minIndex = i;
            } else {
                twoMinNum = Math.min(twoMinNum, arrays.get(i).get(0));
            }
            if(maxNum < arrays.get(i).get(arrays.get(i).size() - 1)){
                twoMaxNum = maxNum;
                maxNum = arrays.get(i).get(arrays.get(i).size() - 1);
                maxIndex = i;
            } else {
                twoMaxNum = Math.max(twoMaxNum, arrays.get(i).get(arrays.get(i).size() - 1));
            }
        }
        if(maxIndex == minIndex) {
            return Math.max(Math.abs(maxNum - twoMinNum), Math.abs(twoMaxNum - minNum));
        }
        return Math.abs(maxNum - minNum);
    }
}