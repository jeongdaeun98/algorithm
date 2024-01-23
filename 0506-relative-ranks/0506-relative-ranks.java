import java.util.*;
class Solution {
    class Medal implements Comparable<Medal>{
        int score;
        int index;
        Medal(int score, int index) {
            this.score = score;
            this.index = index;
        }
        @Override
        public int compareTo(Medal m) {
            return m.score - this.score; 
        }
    }
    public String[] findRelativeRanks(int[] score) {
        PriorityQueue<Medal> pq = new PriorityQueue<>();
        String[] medals = {"Gold Medal","Silver Medal", "Bronze Medal"};
        String[] answer = new String[score.length];
        int count = 0;
        for(int i = 0; i < score.length; i++) {
            pq.offer(new Medal(score[i], i));
        }
        while(!pq.isEmpty()) {
            Medal medal = pq.poll();
            if(count <= 2) {
                answer[medal.index] = medals[count];
            } else {
                answer[medal.index] = Integer.toString(count + 1);
            }
            count++;
        }
        return answer;
    }
}