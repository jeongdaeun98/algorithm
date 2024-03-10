// string 길이부터 1까지 길이를 줄여나가면서 palindrome인지 확인하는 방법
class Solution {
    public String longestPalindrome(String s) {
        for(int i = s.length(); i > 1; i--) {
            for(int j = 0; i + j <= s.length(); j++) {
                boolean valid = true;
                for(int index = 0; index < i / 2; index++) {
                    if(s.charAt(index + j) != s.charAt(j + i - index - 1)) {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    return s.substring(j, j + i);
                }
            }
        }
        return s.substring(0,1);
    }
}