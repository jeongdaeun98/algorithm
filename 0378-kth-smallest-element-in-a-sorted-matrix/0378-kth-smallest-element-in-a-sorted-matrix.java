class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int[] arr= Arrays.stream(matrix).flatMapToInt(Arrays::stream).sorted().toArray();
        return arr[k - 1];
    }
}