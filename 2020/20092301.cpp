#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    for(int i = 1; i <= total; i++){
        int divider = total / i;
        if((divider-2)*(i-2)== yellow){
            if(divider >= i){
                answer.push_back(divider);
                answer.push_back(i);
            }
            else {
                answer.push_back(i);
                answer.push_back(divider);
            }
            break;
        }
    }
    return answer;
}