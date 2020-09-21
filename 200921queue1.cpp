#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0 ; i < progresses.size(); i++){
        int divideNum = (100-progresses[i])/speeds[i];
        int remainder = (100-progresses[i])%speeds[i];
        if(remainder > 0) divideNum++;
        q.push(divideNum);
    }
    int count = 0, maxDay = q.front();
    while(!q.empty()){
        if(maxDay < q.front()) {
            answer.push_back(count);
            maxDay = q.front();
            count = 0;
        }
        count++;
        q.pop();
    }
    answer.push_back(count);
    return answer;
}