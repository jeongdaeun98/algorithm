#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> count(3);
    int firstOne[] = {1,2,3,4,5};
    int secondOne[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int thirdOne[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    for(int i = 0; i < answers.size(); i++){
        if(answers[i]== firstOne[i%5]){
            count[0]++;
        }
        if(answers[i] == secondOne[i%8]){
            count[1]++;
        }
        if(answers[i] == thirdOne[i%10]){
            count[2]++;
        }
    }
    if(count[0] >= count[1] && count[0] >= count[2]){
        answer.push_back(1);
    }
    if(count[1] >= count[0] && count[1] >= count[2]){
        answer.push_back(2);
    }
    if(count[2] >= count[0] && count[2] >= count[1]){
        answer.push_back(3);
    }
    return answer;
}