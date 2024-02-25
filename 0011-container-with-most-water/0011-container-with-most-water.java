// left 0 right height - 1 로 설정
// left와 right 중 더 작은 값을 증가시키면서 이동
// answer와 left와 right 중 더 작은 값 * (right index - left index) 더 큰 거 answer로 설정
// 가장 큰 answer 리턴
class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1, answer = 0;
        while(right > left) {
            answer = Math.max(answer, Math.min(height[right], height[left]) * (right - left));
            if(height[left] > height[right]) {
                right --;
            }else {
                left ++;
            }
        }
        return answer;
    }
}