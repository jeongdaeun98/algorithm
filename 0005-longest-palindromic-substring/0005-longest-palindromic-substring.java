class Solution {
    public String longestPalindrome(String s) {
        for(int i = s.length(); i > 1; i--) {
            for(int j = 0; j + i <= s.length(); j++) {
                String str = s.substring(j, j + i);
                boolean isValid = true;
                for(int k = 0; k < str.length() / 2; k++) {
                    if(str.charAt(k) != str.charAt(str.length() - k - 1)) {
                        isValid = false;
                        break;
                    }
                }
                if(isValid) {
                    return str;
                }
            }
        }
        return s.substring(0,1);
    }
}