
class Solution {
    public int gcd(int strOneLength, int strTwoLength) {
        if(strTwoLength == 0) {
            return strOneLength;
        }
        return gcd(strTwoLength, strOneLength % strTwoLength);
    }
    public boolean isStringGcd(String str, int gcd) {
        int count = gcd;
        String subString = str.substring(0, gcd);
        while(str.length() > count) {
            if(subString.equals(str.substring(count, count + gcd))) {
                count += gcd;
            } else {
                return false;
            }
        }
        return true;
    }
    public String gcdOfStrings(String str1, String str2) {
        int gcdLength = gcd(str1.length(), str2.length());
        
        if(isStringGcd(str1, gcdLength) && isStringGcd(str2, gcdLength) && str1.substring(0,gcdLength).equals(str2.substring(0,gcdLength))) {
            return str1.substring(0,gcdLength);
        }
        return "";
    }
}