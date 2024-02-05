// 내려가는 케이스일 경우,패스& answer ++
// 올라가는 케이스일 경우, 올라가는 벽돌 개수를 pq에 넣음
// pq의 사이즈가 사다리 보다 넘을 때, pq 작은 순으로 빼서 bricks 제거
// bricks가 0 미만일 경우, answer 리턴
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
                bricks -= pq.poll();
            }
            if(bricks < 0) {
                return answer;
            }
            answer++;
        }
        return answer;
    }
}