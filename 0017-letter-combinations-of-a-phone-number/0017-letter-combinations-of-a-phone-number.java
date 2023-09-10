class Solution {
    public List<String> letterCombinations(String digits) {
        Map<Character, String> numberAndLetters = new HashMap<>();
        List<String> answer = new ArrayList<>();
        if(digits.equals("")) {
            return answer;
        }
        numberAndLetters.put('2', "abc");
        numberAndLetters.put('3', "def");
        numberAndLetters.put('4', "ghi");
        numberAndLetters.put('5', "jkl");
        numberAndLetters.put('6', "mno");
        numberAndLetters.put('7', "pqrs");
        numberAndLetters.put('8', "tuv");
        numberAndLetters.put('9', "wxyz");
        List<String> letters = new ArrayList<>();
        for(int i = 0; i < digits.length(); i++) {
            if(numberAndLetters.containsKey(digits.charAt(i))) {
                letters.add(numberAndLetters.get(digits.charAt(i)));
            }
        }
        combination(letters, answer, 0, "");
        return answer;
    }
    public void combination(List<String> letters, List<String> answer, int index, String letter){
        if(letter.length() == letters.size()) {
            answer.add(letter);
            return;
        }
        if(index >= letters.size()) {
            return;
        }
        for(int i = 0; i < letters.get(index).length(); i++) {
            combination(letters, answer, index + 1, letter + letters.get(index).charAt(i));
            combination(letters, answer, index + 1, letter);
        }
    }
}