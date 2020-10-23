#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = number;
    int eraseCount = 0;
    bool eraseTrue = false;
    while(eraseCount != k){
        for(int i = 0; i <= answer.size(); i++){
            if(answer[i] < answer[i+1]){
                answer.erase(answer.begin() + i);
                eraseTrue = true;
                break;
            }
        }
        if(!eraseTrue) answer.erase(answer.end() - 1);
        eraseCount++;
        eraseTrue = false;
    }
    return answer;
}
