import java.util.*;
class Solution {
    //
    // merge조건: 
    // left1 right 1 left 2 right 2
    // right 1 >= left 2
    // 1. left의 조건: 가장 작거나 같은 left
    // 2. right의 조건: 가장 크거나 같은 right
    // 1. 우선 left 기준으로 sort해야 함 
    // 2. 머지된 아이템은 재껴
    public int[][] merge(int[][] intervals) {
        List<List<Integer>> answers = new ArrayList<>();
        Arrays.sort(intervals, new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        int i = 0;
        while(i < intervals.length) {
            if(i + 1 < intervals.length && intervals[i][1] >= intervals[i + 1][0]) {
                List<Integer>answer = new ArrayList<>();
                intervals[i + 1][0] = Math.min(intervals[i][0], intervals[i + 1][0]);
                intervals[i + 1][1] = Math.max(intervals[i][1], intervals[i + 1][1]);
            } else {
                answers.add(Arrays.stream(intervals[i])
                            .boxed()
                            .collect(Collectors.toList()));
            }
            i++;
        }
        return answers.stream()
            .map(item -> item.stream().mapToInt(Integer::intValue).toArray())
            .toArray(int[][]::new);
    }
}