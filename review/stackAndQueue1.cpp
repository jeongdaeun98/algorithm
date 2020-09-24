#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <functional>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    answer.assign(heights.size(), 0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    stack<pair<int,int>> stack;
    for(int i = 0; i < heights.size(); i++)
        stack.push(make_pair(heights[i], i+1));
    while(!stack.empty()){
        pair<int,int> compareNum = stack.top();
        while(!q.empty()&& compareNum.first > q.top().first){
            answer[q.top().second - 1] = compareNum.second;
            q.pop();
        }
        q.push(compareNum);
        stack.pop();
    }
    return answer;
}