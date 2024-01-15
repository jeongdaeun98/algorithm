//1. 2, 3, 5의 배수 중 가장 작은 값을 ugly 수라고 설정한다.
//2. 설정된 값에서 곱한 값을 증가시키면서 ugly 넘버를 구한다. 
class Solution {
    public int nthUglyNumber(int n) {
        int ugly[] = new int[n + 1];
        int two = 1, three = 1, five = 1;
        ugly[1] = 1;
        for(int i = 2; i <= n; i++) {
            ugly[i] = Math.min(Math.min(ugly[two]*2, ugly[three]*3), ugly[five]*5);
            if(ugly[i] == ugly[two] * 2) two++;
            if(ugly[i] == ugly[three] * 3) three++;
            if(ugly[i] == ugly[five] * 5) five++;
        }
        return ugly[n];
    }
}