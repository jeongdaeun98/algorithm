// 2, 3, 5에 곱해지는 수를 1부터 count가 n이 될 때까지 더함
// 가장 작은 수를 ugly number로 설정
class Solution {
    public int nthUglyNumber(int n) {
        int twoMultiply = 0, threeMultiply = 0, fiveMultiply = 0;
        int ugly[] = new int[n];
        int index = 1;
        ugly[0] = 1;
        while(n != index) {
            int uglyNumber = Math.min(ugly[twoMultiply] * 2, Math.min(ugly[threeMultiply] * 3, ugly[fiveMultiply] * 5));
                ugly[index] = uglyNumber;
            
            if(uglyNumber % 2 == 0) {
                twoMultiply++;
            }
            if(uglyNumber % 3 == 0) {
                threeMultiply++;
            }
            if(uglyNumber % 5 == 0) {
                fiveMultiply++;
            }
            index++;
        }
        return ugly[n - 1];
    }
}