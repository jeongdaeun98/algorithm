import java.math.*;
class Solution {
    public int divide(int dividend, int divisor) {
        BigInteger dividendBig = new BigInteger(Integer.toString(dividend));
        BigInteger divisorBig = new BigInteger(Integer.toString(divisor));
        BigInteger bigNum = dividendBig.divide(divisorBig);
        if(bigNum.compareTo(new BigInteger(Integer.toString(Integer.MAX_VALUE))) == 1) {
            return Integer.MAX_VALUE;
        }
        if(bigNum.compareTo(new BigInteger(Integer.toString(Integer.MIN_VALUE))) == -1) {
            return Integer.MIN_VALUE;
        }
        return bigNum.intValue();
    }
}