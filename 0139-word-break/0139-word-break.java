class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> dicts = new HashSet<>();
        for(String word : wordDict) {
            dicts.add(word);
        }
        boolean dp[] = new boolean[s.length() + 1];
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && dicts.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
}