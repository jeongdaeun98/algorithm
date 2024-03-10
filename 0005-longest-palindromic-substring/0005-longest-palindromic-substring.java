class Solution {
    public String longestPalindrome(String s) {
        for (int len = s.length(); len > 1; len--) {
            for (int idx = 0; idx + len <= s.length(); idx++) {
                boolean isValid = true;

                for (int i = 0; i < len / 2; i++) {
                    if (s.charAt(idx + i) != s.charAt(idx + len - i - 1)) {
                        isValid = false;
                        break;
                    }
                }

                if (isValid) {
                    return s.substring(idx, idx + len);
                }
            }
        }

        return s.substring(0, 1);
    }
}