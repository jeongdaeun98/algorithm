// 뒤에서부터 줄여나가면서 palindrome 체크
class Solution {
    public String longestPalindrome(String s) {
        for(int i = s.length(); i > 0; i--) {
            for(int j = 0; i + j <= s.length(); j++) {
                String str = s.substring(j, i + j);
                boolean valid = true;
                for(int k = 0; k < i / 2; k++) {
                    if(str.charAt(k) != str.charAt(str.length() - 1 - k)) {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    return str;
                }
            }
        }
        return s.substring(0,1);
    }
}