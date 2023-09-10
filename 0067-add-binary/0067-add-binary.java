import java.math.BigInteger;
class Solution {
    public String addBinary(String a, String b) {
        BigInteger numberA = new BigInteger(a, 2);
        BigInteger numberB = new BigInteger(b, 2);
        return addBit(numberA, numberB).toString(2);
    }
    
    public BigInteger addBit(BigInteger a, BigInteger b) {
        if(b.compareTo(new BigInteger("0")) == 0) {
            return a;
        }
        BigInteger sum = a.xor(b);
        BigInteger carry = a.and(b).shiftLeft(1);
        return addBit(sum, carry);
    }
}