import java.util.*;
class MinStack {

    Stack<Integer> stack;
    int minNum;
    public MinStack() {
        stack = new Stack<>();
        minNum = Integer.MAX_VALUE;
    }
    
    public void push(int val) {
        if(minNum >= val){
            stack.push(minNum);
            minNum = val;
        }
        stack.push(val);
    }
    
    public void pop() {
        if(minNum == stack.pop()) {
            minNum = stack.pop();
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return minNum;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */