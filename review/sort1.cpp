#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++){
        vector<int> newVector;
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++){
            newVector.push_back(array[j]);
        }
        sort(newVector.begin(),newVector.end());
        answer.push_back(newVector[commands[i][2] - 1]);
    }
    return answer;
}