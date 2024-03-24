class Solution {
    public int nthUglyNumber(int n) {
        int two = 1, three = 1, five = 1;
        int[] ugly = new int[n + 1];
        ugly[1] = 1;
        for(int i = 2; i <= n; i++) {
            int uglyNum = Math.min(ugly[two] * 2, Math.min(ugly[three] * 3, ugly[five] * 5));
            ugly[i] = uglyNum;
            if(uglyNum == ugly[two] * 2) {
                two++;
            }
            if(uglyNum == ugly[three] * 3) {
                three++;
            }
            if(uglyNum == ugly[five] * 5) {
                five++;
            }
        }
        return ugly[n];
    }
}