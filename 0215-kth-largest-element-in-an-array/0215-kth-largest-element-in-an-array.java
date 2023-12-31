import java.util.*;
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer>pq = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i = 0; i < nums.length; i++) {
            pq.offer(nums[i]);
        }
        for(int i = 0; i < k - 1; i++) {
            pq.poll();
        }
        return pq.poll();
    }
}