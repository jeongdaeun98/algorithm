// 순회하면서는 언제나 left + wild >= right
// 나와서는 left > right일 경우, left - right =< wild라면 패스
// left < right 라면, right - left <= wild 라면 패스
class Solution {
    public boolean checkValidString(String s) {
        int left = 0, right = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(') {
                left++;
                right++;
            }else if(s.charAt(i) == ')') {
                right--;
                left--;
            }else {
               left++;
                right--;
            }
            if(left < 0) {
                return false;
            }
            right = Math.max(right, 0);
        }
        return right == 0;
    }
}