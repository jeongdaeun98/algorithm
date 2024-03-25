// 소팅
// 순회
// range의 마지막 범위 저장
// 마지막 범위 < 첫번째 범위라면, answer 증가 마지막 범위 갱신
class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs,(a, b) -> a[1] - b[1]);
        int answer = 1;
        int lastRange = pairs[0][1];
        for(int i = 0; i < pairs.length; i++) {
            if(lastRange < pairs[i][0]) {
                answer++;
                lastRange = pairs[i][1];
            }
        }
        return answer;
    }
}