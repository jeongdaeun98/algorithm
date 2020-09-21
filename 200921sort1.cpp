#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++){
        vector<int> sortingArray;
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++){
            sortingArray.push_back(array[j]);
        }
        sort(sortingArray.begin(), sortingArray.end());
        answer.push_back(sortingArray[commands[i][2]-1]);
    }
    
    return answer;
}