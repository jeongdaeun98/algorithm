import java.util.*;
class Solution {
    public boolean isPalindrome(String s) {
        String string = s.replaceAll("[^a-zA-Z0-9]", "");
        string = string.toLowerCase();
        return checkPalindrome(string);
    }
    
    
    public boolean checkPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}