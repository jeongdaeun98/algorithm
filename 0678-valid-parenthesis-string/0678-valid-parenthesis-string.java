//
class Solution {
    public boolean checkValidString(String s) {
        int leftMax = 0, leftMin = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(') {
                leftMax++;
                leftMin++;
            } else if(s.charAt(i) == ')'){
                leftMax--;
                leftMin--;
            }else{
                leftMax++;
                leftMin--;
            }
            if(leftMax < 0) {
                return false;
            }
            leftMin = Math.max(leftMin, 0);
        }
        return leftMin == 0;
    }
}