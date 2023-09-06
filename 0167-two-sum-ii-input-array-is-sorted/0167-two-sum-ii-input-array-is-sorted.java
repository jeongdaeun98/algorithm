import java.util.*;
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        List<Integer> answer = new ArrayList();
        Map<Integer, Integer> numberAndIndex = new HashMap<>();
        Set<Integer> wantedNums = new HashSet<>();
        for(int i = 0 ; i < numbers.length; i++) {
            if(!wantedNums.contains(numbers[i])){
                numberAndIndex.put(numbers[i], i + 1);
                wantedNums.add(target - numbers[i]);
            } else {
                answer.add(numberAndIndex.get(target -numbers[i]));
                answer.add(i + 1);
                break;
            }
        }
        return answer.stream().mapToInt(e -> e).toArray();
    }
}