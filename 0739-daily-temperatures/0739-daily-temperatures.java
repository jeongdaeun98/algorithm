//1. stack에 값을 넣을 때, 인덱스를 넣음
//2. 맨 앞 값보다 작은 값이라면 STack에 넣음
//3. 저장된 인덱스보다 큰 값이라면 기존 값 빼고, 현 인덱스 - 기존 값 을 기존 값에 넣고, 다시 넣음.
//4. 만들어진 array 리턴
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] answer = new int[temperatures.length];
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        for(int i = 1; i < temperatures.length; i++){
            while(!stack.isEmpty() && temperatures[stack.peek()] < temperatures[i]) {
                answer[stack.peek()] = i - stack.peek();
                stack.pop();
            }
            stack.push(i);
        }
        return answer;
    }
}