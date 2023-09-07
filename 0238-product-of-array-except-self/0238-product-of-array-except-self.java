class Solution {
    public int[] productExceptSelf(int[] nums) {
        List<Integer> leftRotate = new ArrayList<>();
        List<Integer> rightRotate = new ArrayList<>();
        for(int i = 0; i < nums.length; i++) {
            leftRotate.add(1);
            rightRotate.add(1);
        }
        int left = 1;
        int right = nums.length - 2;
        while(left < nums.length) {
            leftRotate.set(left, leftRotate.get(left - 1) * nums[left - 1]);
            left ++;
        }
        while(right >= 0) {
            rightRotate.set(right,rightRotate.get(right + 1) * nums[right + 1]);
        
            right --;    
        }
        for(int i = 0; i < nums.length; i++){
            rightRotate.set(i, leftRotate.get(i) * rightRotate.get(i));
        }
        
        return rightRotate.stream().mapToInt(e->e).toArray();
    }
}