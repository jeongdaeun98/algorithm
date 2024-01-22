class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int h = matrix.length, w = matrix[0].length;
        int s = matrix[0][0], e = matrix[h - 1][w - 1];
        while (s < e) {
            int m = (s + e) >> 1;
            int count = 0;
            for (int i = 0; i < h; i++) {
                int l=0;
                int r=w;
                while(l<r){
                    int mid=(l+r)>>1;
                    if(matrix[i][mid]<=m) l= mid+1;
                    else r=mid;
                }
                count += r;
            }
            if (count < k)  s = m + 1;  
            else  e = m; 
        }
        return s;
    }
}