//1. nums에 대해 sort를 하는데, 두개를 이어 붙였을 때 더 큰 값 순으로 정렬되도록 함.
import java.util.*;
import java.math.*;
class Solution {
    public String largestNumber(int[] nums) {
        List<Integer> numbers = Arrays.stream(nums).boxed().collect(Collectors.toList());
        Collections.sort(numbers, (o1, o2) -> {
            String o1Str = Integer.toString(o1);
            String o2Str = Integer.toString(o2);
            BigInteger o1o2 = new BigInteger(o1Str + o2Str);
            BigInteger o2o1 = new BigInteger(o2Str + o1Str);
            if(o1o2.compareTo(o2o1) > 0) {
                return -1;
            } else if(o1o2.compareTo(o2o1) < 0) {
                return 1;
            } else {
                return 0;
            }
        });
        if(numbers.get(0) == 0) {
            return "0";
        }
        return numbers.stream().map(num -> Integer.toString(num)).collect(Collectors.joining(""));
    }
}