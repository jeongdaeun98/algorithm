class Solution {
    public int longestConsecutive(int[] nums) {
        int answer = 0;
        List<Integer> distinctedNums = Arrays.stream(nums).boxed().distinct().sorted().collect(Collectors.toList());
        int count = 0;
        for(int i = 0; i < distinctedNums.size(); i++) {
            if(i - 1 >= 0 && distinctedNums.get(i - 1) + 1 != distinctedNums.get(i)){
                answer = Math.max(answer, count);
                count = 0;
            }
            count++;
        }
        return Math.max(answer, count);
    }
}