// solution에서 누적합 구함
// pickIndex에서 random 수 구하고
// 랜덤 수가 인덱스 돌리면서 누적합 수보다 낮을 경우 그 인덱스를 던짐
class Solution {
    Random random;
    int[] sum;
    int total;
    public Solution(int[] w) {
        random = new Random();
        sum = new int[w.length];
        total = 0;
        for(int i = 0; i < w.length; i++) {
            total += w[i];
            sum[i] = total;
        }
    }
    
    public int pickIndex() {
        int randNumber = random.nextInt(total);
        for(int i = 0; i < sum.length; i++) {
            if(randNumber < sum[i]) {
                return i;
            }
        }
        return -1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */