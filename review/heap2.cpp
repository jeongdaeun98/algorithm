#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0, j = 0, day = 0;
    priority_queue<int> pq;
    while(1){
       if(dates[j] == day){
           pq.push(supplies[j]);
           j++;
       }
        if(stock == 0){
            stock = pq.top();
            pq.pop();
            answer++;
            if(k-day <= stock) return answer;
        }
        day++;
        stock--;
    }
    return answer;
}