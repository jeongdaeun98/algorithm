import java.util.*;
class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int answer = 0;
        for(int i = 0; i < heights.length - 1; i++) {
            if(heights[i] < heights[i + 1]) {
                pq.offer(heights[i + 1] - heights[i]);
            }
            if(pq.size() > ladders) {
                bricks -=  pq.poll();
            }
            if(bricks < 0) {
                return answer;
            }
            answer++;
        }
        return heights.length - 1;
    }
}