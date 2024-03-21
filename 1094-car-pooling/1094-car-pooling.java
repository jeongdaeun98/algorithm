class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[]locations = new int[1001];
        for(int i = 0; i < trips.length; i++) {
            for(int j = trips[i][1]; j <= trips[i][2]; j++){
                locations[j] += trips[i][0];
            }
            locations[trips[i][2]] -= trips[i][0];
        }
        for(int i = 0; i <= 1000; i++) {
            if(locations[i] > capacity){
                return false;
            }
        }
        return true;
    }
}