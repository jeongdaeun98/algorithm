// s 배열 false로 초기화
// wordDict를 hashmap으로 초기화
// 순회
// hashMap에 있다면 그 다음 index true로
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] contains = new boolean[s.length() + 1];
        Set<String> words = new HashSet<>(wordDict);
        contains[0] = true;
        for(int i = 1; i <= s.length(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                String str = s.substring(j, i);
                if(contains[j] && words.contains(str)) {
                    contains[i] = true;
                    break;
                }
            }
        }
        return contains[s.length()];
    }
}