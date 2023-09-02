import java.util.*;
class Solution {
    public boolean isValid(String s) {
        String leftBracket = "({[";
        String rightBracket = ")}]";
        Stack<Integer> leftBrackets = new Stack();
        String[] splitedStrings = s.split("");
        for(String splitedString : splitedStrings) {
            if(leftBracket.contains(splitedString)) {
                leftBrackets.push(leftBracket.indexOf(splitedString));
            } else {
                if(leftBrackets.size() == 0) {
                    return false;
                }
                if(leftBrackets.peek() == rightBracket.indexOf(splitedString)){
                    leftBrackets.pop();
                } else {
                    return false;
                }
            }
        }
        if(leftBrackets.size() != 0) {
            return false;
        }
        return true;
    }
}