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
                if(leftMin > 0){
                    leftMin--;
                }
            }else{
                leftMax++;
                if(leftMin > 0) {
                    leftMin--;
                }
            }
            if(leftMax < 0) {
                return false;
            }
        }
        return leftMin == 0;
    }
}