// 인덱스대로 스택에 저장
// 해당 인덱스가 가리키는 값과 순회하는 값 비교 후, 순회 값이 더 크면 인덱스 빼냄
// 그 인덱스에 순회 값 - 인덱스 가리키는 값
// int 배열 리턴
import java.util.*;
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] answer = new int[temperatures.length];
        Arrays.fill(answer, 0);
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < temperatures.length; i++) {
            while(!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]){
                int index = stack.pop();
                answer[index] = i - index;
            }
            stack.push(i);
        }
        return answer;
    }
}