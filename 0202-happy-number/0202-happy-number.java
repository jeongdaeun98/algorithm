import java.util.*;
import java.math.BigInteger;
class Solution {
    public boolean isHappy(int n) {
        Set<BigInteger> squareDigits = new HashSet<>();
        String number = Integer.toString(n);
        BigInteger happyNum = new BigInteger("0");
        while(!squareDigits.contains(happyNum)){
            squareDigits.add(happyNum);
            happyNum = new BigInteger("0");
            for(int i = 0 ; i < number.length(); i++) {
                BigInteger num = new BigInteger(Character.toString(number.charAt(i)));
                num = num.multiply(num);
                happyNum = happyNum.add(num);
            }
            number = happyNum.toString();
        }
        if(squareDigits.contains(new BigInteger("1"))) {
            return true;
        }
        return false;
    }
}