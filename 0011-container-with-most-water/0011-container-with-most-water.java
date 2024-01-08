class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
        int answer = 0;
        while(left < right) {
            if(height[left] < height[right]) {
                answer = Math.max((right - left)*height[left], answer);
                left++;
            } else {
                answer = Math.max((right - left)*height[right], answer);
                right--;
            }
        }
        return answer;
    }
}