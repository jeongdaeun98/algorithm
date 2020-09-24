#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0; i < progresses.size(); i++){
        int num = 100 - progresses[i];
        q.push(ceil(num/speeds[i]));
    }
    int max = q.front();
    int count = 0;
    while(!q.empty()){
        if(max < q.front()){
            answer.push_back(count);
            count = 0;
            max = q.front();
        }
        count++;
        q.pop();
    }
    answer.push_back(count);
    return answer;
}