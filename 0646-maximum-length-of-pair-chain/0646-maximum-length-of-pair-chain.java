//왼쪽 수대로 정렬
// 이중 포문으로 맨 앞부터 뒤에까지 pair 개수 많은 거 리턴
class Solution {
    public int findLongestChain(int[][] pairs) {
        int answer = 1;
        Arrays.sort(pairs, (a1, a2) -> {
            if(a1[0] == a2[0]) {
                return a1[1] - a2[1];
            }
            return a1[0] - a2[0];
        });
        for(int i = 0; i < pairs.length; i++) {
            int left = pairs[i][0];
            int right = pairs[i][1];
            int count = 1;
            for(int j = i + 1; j < pairs.length; j++) {
                if(right > pairs[j][1]) {
                    right = pairs[j][1];
                    left = pairs[j][0];
                } else if(pairs[j][0] > right) {
                    count++;
                    left = pairs[j][0];
                    right = pairs[j][1];
                }
                answer = Math.max(answer, count);
                
            }
        }
        return answer;
    }
}