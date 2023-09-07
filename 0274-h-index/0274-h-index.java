import java.util.*;
class Solution {
    public int hIndex(int[] citations) {
        List<Integer> citationAndCount = new ArrayList<>();
        List<Integer> copy = Arrays.stream(citations).boxed().sorted(Collections.reverseOrder()).collect(Collectors.toList()); 
        int max = copy.get(0);
        for(int i = 0; i <= max; i++) {
            int count = 0;
            for(int j = 0; j < copy.size(); j++) {
                if(copy.get(j) >= i) {
                    count++;
                }
            }
            citationAndCount.add(count);
        }
        for(int i = max; i >= 0; i--) {
            if(i <= citationAndCount.get(i)) {
                return i;
            }
        }
        return 0;
    }
}