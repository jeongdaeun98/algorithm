// dfs
// 빼는 경우, 더하는 경우로 나누어 계산
class Solution {
    int answer = 0;
    public void dfs(int target, int[]numbers, int sum, int count) {
        if(count == numbers.length) {
            if(sum == target) {
                answer ++;
            }
            return;
        }
        dfs(target, numbers, sum -1 * numbers[count], count + 1);
        dfs(target, numbers, sum + numbers[count], count + 1);
        
    }
    public int solution(int[] numbers, int target) {
        dfs(target, numbers, 0, 0);
        return answer;
    }
}
