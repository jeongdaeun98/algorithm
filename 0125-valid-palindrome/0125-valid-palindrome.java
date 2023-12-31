class Solution {
    public boolean isPalindrome(String s) {
        s = s.trim();
        s = s.toLowerCase();
        s = s.replaceAll("[^a-z\\d]","");
        StringBuilder sb = new StringBuilder(s);
        String str = sb.reverse().toString();
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) != str.charAt(i)){
                return false;
            }
        }
        return true;
    }
}