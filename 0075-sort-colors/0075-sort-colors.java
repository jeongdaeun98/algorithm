// left = 0, right = nums.length - 1
// i로 순회
// i가 0일 경우, left와 i swap 후 left와 i 증가
// i가 1일 경우, i 증가
// i가 2일 경우, right와 i swap 후 r만 감소
class Solution {
    public void sortColors(int[] nums) {
        int left = 0, right = nums.length - 1;
        for(int i = 0; i <= right;) {
            if(nums[i] == 0) {
                swap(nums, i++, left++);
            }else if(nums[i] == 1) {
                i++;
            }else {
                swap(nums, i, right--);
            }
        }
    }
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}