import java.math.BigInteger;
class Solution {
    public int singleNumber(int[] nums) {
        String sum = "";
        int[] digit = new int[32];
        Arrays.fill(digit, 0);
        for(int i = 0; i < nums.length; i++) {
            String number = Integer.toBinaryString(nums[i]);
            for(int j = 0; j < number.length(); j++) {
                if(number.charAt(j) == '1'){
                    digit[number.length() - 1 - j]++;
                }
            }
        }
        for(int i = digit.length - 1; i >= 0; i--) {
            if(digit[i] % 3 > 0){
                sum += "1";
            } else {
                sum += "0";
            }
        }
        return new BigInteger(sum, 2).intValue();
    }
}