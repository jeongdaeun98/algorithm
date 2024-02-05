// left right 포인터 설정
// left와 right 중 값이 작은 애 인덱스를 증가
// Math.min(height[left], height[right]) * (right - left)
// left가 right 넘을 때까지 반복
class Solution {
    public int maxArea(int[] height) {
        int answer = 0;
        int left = 0, right = height.length - 1;
        while(left < right) {
            answer = Math.max(answer, Math.min(height[left], height[right]) * (right - left));
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return answer;
    }
}