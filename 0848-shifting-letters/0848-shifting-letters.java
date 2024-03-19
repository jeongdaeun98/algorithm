// 3 5 9
//17 14 9
// a  b c
// a 3 + 5 + 9 
// b 5 + 9 
// c 9
// 뒤부터 누적합
// z-a + 1을 배열크기로
// 인덱스 - a % 배열크기
class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        int[] sum = new int[shifts.length + 1];
       
        for(int i = shifts.length - 1; i >= 0; i--) {
            sum[i] = (shifts[i] + sum[i + 1]) % ('z' - 'a' + 1);
        }
        String answer = "";
        for(int i = 0; i < s.length(); i++) {
            answer += Character.toString((s.charAt(i) - 'a' + sum[i]) % ('z' - 'a' + 1) + 'a');
        }
        return answer;
    }
}