class Result {
    public static String isBalanced(String s) {
        List<Character> open = Arrays.asList('(','{','[');
        List<Character> close = Arrays.asList(')','}',']');
        Stack<Character>stack = new Stack<>();
        for(int i = 0; i < s.length(); i++) {
            if(close.contains(s.charAt(i))) {
                if(stack.isEmpty() || stack.peek() != open.get(close.indexOf(s.charAt(i)))) {
                    return "NO";
                }
                stack.pop();
            } else {
                stack.push(s.charAt(i));
            }
        }
        if(stack.isEmpty()) {
            return "YES";
        }
        return "NO";
    }

}