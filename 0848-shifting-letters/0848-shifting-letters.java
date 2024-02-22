// 누적해서 sum 구함
// 1의 자릿 수부터 sum[shifts.length - 1] sum[shifts.length - 1] - sum[0].... % ('z' - 'a')
class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        int[] sum = new int[shifts.length];
        sum[0] = shifts[0];
        for(int i = 1; i < shifts.length; i++) {
            sum[i] = shifts[i] % 26 + sum[i - 1];
        }
        String answer = "";
        for(int i = 0; i < s.length(); i++) {
            if (i - 1 >= 0){
            answer += Character.toString((s.charAt(i) - 'a' + sum[s.length() - 1] - sum[i - 1])%26 + 'a');
            } else {
                answer += Character.toString((s.charAt(i) - 'a' + sum[s.length() - 1]) %26 + 'a');
            }
        }
        return answer;
    }
}