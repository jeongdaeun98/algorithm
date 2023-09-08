import java.util.Stack;
class Solution {
    public String simplifyPath(String path) {
        String answer = "";
        path = path.replaceAll("/+", "/");
        String[] pathSplit = path.split("/");
        Stack<String> stack = new Stack<>();
        for(int i = 0; i < pathSplit.length; i++) {
            if(pathSplit[i].equals("")) {
                continue;
            }
            if(pathSplit[i].equals("..") && !stack.empty()){
                stack.pop();
            } else if(!pathSplit[i].equals(".") && !pathSplit[i].equals("..")) {
                stack.push(pathSplit[i]);
            }
        }
        Stack<String> reverseStack = new Stack<>();
        while(!stack.empty()) {
            reverseStack.push(stack.peek());
            stack.pop();
        }
        while(!reverseStack.empty()) {
            answer += "/" + reverseStack.peek();
            reverseStack.pop();
        }
        if(answer.equals("")) {
            answer += "/";
        }
        return answer;
    }
}