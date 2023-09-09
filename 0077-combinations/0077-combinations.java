class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> answers = new ArrayList<>();
        List<Integer> numbers = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            numbers.add(i + 1);
        }
        int[] answer = new int[k];
        combination(k - 1, answers, answer, 0, numbers);
        return answers;
    }
    
    public void combination(int depth, List<List<Integer>> answers, int[] answer,int index, List<Integer> numbers) {
        if(depth < 0) {
            answers.add(Arrays.stream(answer).boxed().collect(Collectors.toList()));
            return;
        }
        if(index >= numbers.size()) {
            return;
        }
        combination(depth, answers, answer, index + 1, numbers);
        answer[depth] = numbers.get(index);
        combination(depth -1, answers, answer, index + 1, numbers);
    }
}