class Solution {
    public double myPow(double x, int n) {
        if(n == 0) {
            return 1;
        }
        if(n < 0) {
            if((n * -1) % 2 == 0) {
               double temp = myPow(x, n / 2 * -1);
                return 1 / (temp * temp);
            } else {
                double temp = myPow(x, n / 2 * -1);
                return 1 / (temp * temp * x);
            }
        } else {
            if(n % 2 == 0) {
                double temp = myPow(x, n / 2);
                return temp * temp;
            } else {
                double temp = myPow(x, n / 2);
                return temp * temp * x;
            }
        }
    }
}