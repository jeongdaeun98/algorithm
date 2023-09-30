import java.util.*;
// 0 1 2 3 4 5 6
//[1,2,3,4,5,6,7]
// k = 3
// 3 4 5 6 0 1 2
//[5,6,7,1,2,3,4]
class NumIndex {
    int number;
    int index;
    public NumIndex(int number, int index) {
        this.number = number;
        this.index = index;
    }
}
class Solution {
    public void rotate(int[] nums, int k) {
        int index;
        List<NumIndex> numbers = new ArrayList<>();
        for(int i = 0; i < nums.length; i++) {
            index = (k + i) % nums.length;
            numbers.add(new NumIndex(nums[i], index));
        }
        for(int i = 0; i < numbers.size(); i++) {
            NumIndex numIndex = numbers.get(i);
            nums[numIndex.index] = numIndex.number;
        }
    }
}