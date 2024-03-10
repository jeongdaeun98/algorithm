// string 길이부터 1까지 길이를 줄여나가면서 palindrome인지 확인하는 방법
class Solution {
    public String longestPalindrome(String s) {
        for(int size = s.length(); size > 1; size--) {
            for(int j = 0; size + j <= s.length(); j++) {
                boolean valid = true;
                for(int i = 0; i < size / 2; i++) {
                    if(s.charAt(i + j) != s.charAt(j + size - i - 1)) {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    return s.substring(j, j + size);
                }
            }
        }
        return s.substring(0,1);
    }
}