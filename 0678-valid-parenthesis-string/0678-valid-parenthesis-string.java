// 왼쪽이 *로 대체되는 경우, 오른쪽이 *로 대체되는 경우를 나누어서 저장.
// 왼쪽인 경우, 오른쪽이 0보다 크다면 false를
// 오른쪽인 경우, 왼쪽이 0보다 작다면 false를
// 그 외라면 true 리턴
class Solution {
    public boolean checkValidString(String s) {
        int left = 0, right = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c == '(') {
                left ++;
                right ++;
            } else if(c == ')') {
                left --;
                right --;
            } else {
                left ++;
                right --;
            }
            if(left < 0) {
                return false;
            }
            right = Math.max(right, 0);
        }
        return right == 0;
    }
}