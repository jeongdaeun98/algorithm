class RecentCounter {
    Queue<Integer> q;
    public RecentCounter() {
        q = new LinkedList<>();
    }
    
    public int ping(int t) {
        q.offer(t);
        int left = t - 3000;
        int right = t;
        int size = q.size();
        int count = 0;
        for(int i = 0; i < size; i++) {
            int num = q.poll();
            if(left <= num && num <= right) {
                count++;
                q.offer(num);
            }
        }
        return count;    
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */