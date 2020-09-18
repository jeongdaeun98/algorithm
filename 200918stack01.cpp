#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> stack;
    for(int i = 0; i < prices.size(); i++){
        while(!stack.empty()&&prices[stack.top()]<prices[i]){
            answer[stack.top()] = i - stack.top();
            stack.pop();
        }
        stack.push(i);
    }
    while(!stack.empty()){
        answer[stack.top()] = prices.size() - stack.top() - 1;
        stack.pop();
    }
    return answer;
}