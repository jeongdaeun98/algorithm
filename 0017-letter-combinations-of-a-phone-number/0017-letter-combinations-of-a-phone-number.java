import java.util.*;
class Solution {
    public List<String> letterCombinations(String digits) {
        Map<Integer, String> numberAndDigits = new HashMap<>();
        numberAndDigits.put(2, "abc");
        numberAndDigits.put(3, "def");
        numberAndDigits.put(4, "ghi");
        numberAndDigits.put(5, "jkl");
        numberAndDigits.put(6, "mno");
        numberAndDigits.put(7, "pqrs");
        numberAndDigits.put(8, "tuv");
        numberAndDigits.put(9, "wxyz");
        List<String> digit = new ArrayList<>();
        for(int i = 0; i < digits.length(); i++) {
            digit.add(numberAndDigits.get(digits.charAt(i) - '0'));
        }
        List<String> answers = new ArrayList<>();
        combination(answers, "", 0, digit);
        if(digits.equals("")) {
            return new ArrayList<>();
        }
        return answers;
    }
    public void combination(List<String> answers, String answer, int index, List<String> digits) {
        if(answer.length() == digits.size()) {
            answers.add(answer);
            return;
        }
        if(index == digits.size()) {
            return;
        }
        for(int i = 0; i < digits.get(index).length(); i++) {
            combination(answers, answer + digits.get(index).charAt(i), index + 1, digits);
            combination(answers, answer, index + 1, digits);
        }
    }
}