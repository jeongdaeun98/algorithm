class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int[] leftSum = new int[k + 1];
        int[] rightSum = new int[k + 1];
        leftSum[1] = cardPoints[0];
        rightSum[1] = cardPoints[cardPoints.length - 1];
        for(int i = 2; i <= k; i++) {
            leftSum[i] += leftSum[i - 1] + cardPoints[i - 1];
            rightSum[i] += rightSum[i - 1] + cardPoints[cardPoints.length - i];
        }
        int result = 0;
        for(int i = 0; i <= k; i++) {
            result = Math.max(result, leftSum[i] + rightSum[k - i]);
        }
        return result;
    }
}