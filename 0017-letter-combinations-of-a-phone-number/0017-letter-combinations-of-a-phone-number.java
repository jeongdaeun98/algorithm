import java.util.*;
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> answers = new ArrayList<>();
        Map<String, List<String>> digitAndAlphabet = new HashMap<>();
        digitAndAlphabet.put("2", Arrays.asList("a","b", "c"));
        digitAndAlphabet.put("3", Arrays.asList("d","e", "f"));
        digitAndAlphabet.put("4", Arrays.asList("g","h", "i"));
        digitAndAlphabet.put("5", Arrays.asList("j","k", "l"));
        digitAndAlphabet.put("6", Arrays.asList("m","n", "o"));
        digitAndAlphabet.put("7", Arrays.asList("p","q", "r","s"));
        digitAndAlphabet.put("8", Arrays.asList("t","u", "v"));
        digitAndAlphabet.put("9", Arrays.asList("w","x", "y", "z"));
        List<List<String>> alphabet = new ArrayList<>();
        for(int i = 0; i < digits.length(); i++){
            String str = Character.toString(digits.charAt(i));
            if(digitAndAlphabet.containsKey(str)){
                alphabet.add(digitAndAlphabet.get(str));
            }
        }
        combination("", answers, alphabet, 0, 0);
        return answers;
    }
    public void combination(String answer, List<String> answers, List<List<String>> alphabet, int index, int target) {
        if(target == alphabet.size() && !answer.equals("")) {
            answers.add(answer);
            return;
        }
        if(target == alphabet.size() || alphabet.get(target).size() <= index) {
            return;
        }
        for(int i = index; i < alphabet.get(target).size(); i++){
            combination(answer + alphabet.get(target).get(i), answers, alphabet, index, target + 1);
        }
    }
}