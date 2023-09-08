import java.util.*;
class Solution {
    enum Operator {
    PLUS("+", (num1, num2) -> num2 + num1),
    MINUS("-", (num1, num2) -> num2 - num1),
    MULTIPLY("*", (num1, num2) -> num2 * num1),
    DIVIDE("/", (num1, num2) -> num2 / num1);

    private String operator;
    private BiFunction<Integer, Integer, Integer> expression;

    Operator(String operator, BiFunction<Integer, Integer, Integer> expression) {
        this.operator = operator;
        this.expression = expression;
    }

    public static int calculate(String operator, int num1, int num2) {
        return getOperator(operator).expression.apply(num1, num2);
    }
    private static Operator getOperator(String operator) {
        return Arrays.stream(values())
                .filter(o -> o.operator.equals(operator))
                .findFirst().orElse(null);
    }
}
    
    public int evalRPN(String[] tokens) {
        Set<String> operator = new HashSet<>();
        Stack<Integer> number = new Stack<>();
        operator.add("+");
        operator.add("-");
        operator.add("/");
        operator.add("*");
        for(int i = 0; i < tokens.length; i++){
            while(i < tokens.length && operator.contains(tokens[i])) {
                int num = Operator.calculate(tokens[i], number.pop(), number.pop());
                number.add(num);
                i++;
            }
            if(i < tokens.length){
                number.add(Integer.parseInt(tokens[i]));
            }
        }
        return number.pop();
    }
}