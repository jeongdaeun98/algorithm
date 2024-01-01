import java.util.*;
class Solution {
    public List<String> letterCombinations(String digits) {
        Map<Integer, String> numAndDigits = new HashMap<>();
        numAndDigits.put(2, "abc");
        numAndDigits.put(3, "def");
        numAndDigits.put(4, "ghi");
        numAndDigits.put(5, "jkl");
        numAndDigits.put(6, "mno");
        numAndDigits.put(7, "pqrs");
        numAndDigits.put(8, "tuv");
        numAndDigits.put(9, "wxyz");
        List<String>digitList = new ArrayList<>();
        for(int i = 0; i < digits.length(); i++) {
            digitList.add(numAndDigits.get(digits.charAt(i) - '0'));
        }
        List<String> answers = new ArrayList<>();
        if("".equals(digits)) {
            return new ArrayList<>();
        }
        combination(answers, "", digitList, 0);
        return answers;
    }
    public void combination(List<String> answers, String answer, List<String> digits, int index) {
        if(answer.length() == digits.size()) {
            answers.add(answer);
            return;
        }
        if(index == digits.size()) {
            return;
        }
        for(int i = 0; i < digits.get(index).length(); i++){
            combination(answers, answer + digits.get(index).charAt(i), digits, index + 1);
            combination(answers, answer,digits, index + 1);
        }
    }
}