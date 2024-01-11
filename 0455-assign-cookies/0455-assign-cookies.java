// 아이와 쿠기 크기에 대해 내림차순으로 priority queue에 입력
// 아이의 탐욕지수가 쿠키 크기보다 작거나 같으면 answer 증가 후 queue에서 빼냄
// 그렇지 않으면 answer 냅두고, 탐욕 지수만 빼냄
import java.util.*;
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int answer = 0;
        PriorityQueue<Integer> gpq = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> spq = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i = 0; i < g.length; i++) {
            gpq.offer(g[i]);
        }
        for(int i = 0; i < s.length; i++) {
            spq.offer(s[i]);
        }
        while(!gpq.isEmpty() && !spq.isEmpty()) {
            if(gpq.peek() <= spq.peek()) {
                spq.poll();
                answer++;
            }
            gpq.poll();
        }
        return answer;
    }
}