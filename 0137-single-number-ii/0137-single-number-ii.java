import java.math.BigInteger;
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        for(int i = 0; i < nums.length - 2; i = i + 3) {
            BigInteger a = new BigInteger(Integer.toBinaryString(nums[i]), 2);
            BigInteger b = new BigInteger(Integer.toBinaryString(nums[i + 1]), 2);
            BigInteger c = new BigInteger(Integer.toBinaryString(nums[i + 2]), 2);
            BigInteger zero = new BigInteger("0");
            if(a.xor(b).compareTo(zero) != 0 && b.xor(c).compareTo(zero) == 0) {
                return a.intValue();
            }
        }
        return nums[nums.length - 1];
    }
}