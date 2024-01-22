import java.util.*;
class Solution {
    class Number {
        int i,j,sum;
        Number(int i, int j, int sum) {
            this.i = i;
            this.j = j;
            this.sum = sum;
        }
    }
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<Number> pq = new PriorityQueue<>(new Comparator<Number>() {
            @Override
            public int compare(Number a1, Number a2) {
                return a1.sum - a2.sum;
            }
        });
        List<List<Integer>> answers = new ArrayList<>();
        for(int i = 0; i < nums1.length; i++) {
            pq.offer(new Number(i, 0, nums2[0] + nums1[i]));
        }
       
        while(k != 0 && !pq.isEmpty()) {
            Number number = pq.poll();
            k--;
            int i = number.i;
            int j = number.j;
            answers.add(Arrays.asList(nums1[i],nums2[j]));
            if(j + 1 < nums2.length) {
                pq.offer(new Number(i, j + 1, nums1[i] + nums2[j + 1]));
            }
        }
        return answers;
    }
}