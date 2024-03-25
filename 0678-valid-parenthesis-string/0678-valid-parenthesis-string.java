// leftMax leftMin으로 계산
// max일 경우 *에 대해 ++, min은 *에 대해 --
// min이 0보다 클 경우 
class Solution {
    public boolean checkValidString(String s) {
        int leftMax = 0, leftMin = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == ')'){
                leftMax--;
                if(leftMin > 0) {
                    leftMin--;
                }
            } else if(s.charAt(i) == '(') {
                leftMax++;
                leftMin++;
            } else {
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