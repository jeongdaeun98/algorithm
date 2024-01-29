import java.util.*;
class Solution {
    class Frequency implements Comparable<Frequency>{
        int count;
        String alphabet;
        Frequency(int count, String alphabet) {
            this.count = count;
            this.alphabet = alphabet;
        }
        @Override
        public int compareTo(Frequency f) {
            return this.count - f.count;
        }
        
        public Frequency getMinusCount() {
            this.count--;
            return this;
        }
    }
    public String reorganizeString(String s) {
        PriorityQueue<Frequency> pq = new PriorityQueue<>(Comparator.reverseOrder());
        Map<String, Integer> frequency = new HashMap<>();
        for(int i = 0; i < s.length(); i++) {
            String alphabet = Character.toString(s.charAt(i));
            frequency.put(alphabet, frequency.getOrDefault(alphabet, 0) + 1);
        }
        for(String alphabet : frequency.keySet()) {
            pq.add(new Frequency(frequency.get(alphabet),alphabet));
        }
        String answer = "";
        while(!pq.isEmpty()) {
            Frequency f1 = pq.poll();
            Frequency f2;
            if(!pq.isEmpty()){
                f2 = pq.poll();
            } else {
                if(f1.count > 1) {
                    return "";
                }
                return answer + f1.alphabet;
            }
            answer += f1.alphabet + f2.alphabet;
            f1 = f1.getMinusCount();
            if(f1.count > 0){
                pq.add(f1);
            }
            f2 = f2.getMinusCount();
            if(f2.count > 0){
                pq.add(f2);
            }
        }
        return answer;
    }
}