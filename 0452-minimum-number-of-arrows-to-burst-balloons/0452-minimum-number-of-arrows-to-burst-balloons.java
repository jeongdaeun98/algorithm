class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        int count = 0;
        int point = points[0][1];
        for(int i = 1; i < points.length; i++) {
            if(!(point <= points[i][1] && point >= points[i][0])) {
                count++;
                point = points[i][1];
            }
        }
        return count + 1;
    }
}