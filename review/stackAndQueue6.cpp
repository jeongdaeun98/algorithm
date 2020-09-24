#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    bool answerTrue = false;
    for(int i = 0; i < prices.size(); i++){
        for(int j = i+1; j < prices.size(); j++){
            if(prices[i] > prices[j]){
                answer.insert(answer.begin() + i, j - i);
                answerTrue = true;
                break;
            }
        }
        if(!answerTrue) answer.insert(answer.begin() + i, prices.size() - 1 - i);
        answerTrue = false;
    }
    return answer;
}