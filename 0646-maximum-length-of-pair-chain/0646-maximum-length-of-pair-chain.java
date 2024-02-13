// 다음 인자의 left는 반드시 인자의 right보다 크기 때문에
// 정렬
// 순회
// right를 마지막 range로 설정
// 다음 인자의 left와 비교하여 left가 클 경우, answer증가하면서 마지막 range 를 right로 설정
class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a,b) -> a[1] - b[1]);
        int answer = 1;
        int lastRange = pairs[0][1];
        for(int i = 1; i < pairs.length; i++) {
            if(lastRange < pairs[i][0]) {
                answer++;
                lastRange = pairs[i][1];
            }
        }
        return answer;
    }
}