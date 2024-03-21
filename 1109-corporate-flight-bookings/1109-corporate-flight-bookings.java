// 범위 시작의 의미로 3번째 숫자 더함
// 범위 끝나면 3번째 숫자로 뺌
// 0~n-1까지 이전 값으로 더해줌
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] answer = new int[n];
        for(int i = 0; i < bookings.length; i++) {
            answer[bookings[i][0] - 1] += bookings[i][2];
            if(bookings[i][1] != n){
                answer[bookings[i][1]] -= bookings[i][2];
            }
        }
        for(int i = 1; i < n; i++) {
            answer[i] += answer[i - 1];
        }
        return answer;
    }
}