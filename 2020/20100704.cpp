#include <vector>
#include <unordered_map>

using namespace std;

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    vector<int> answer;
    unordered_map<int, int> numberHash;
    vector<int> countVector(queries.size() + 1);
    for(int i = 0; i <= queries.size(); i++){
        countVector[i] = 0;
    }
    for(int i = 0; i < queries.size(); i++){
        if(queries[i][0] == 1){
            unordered_map<int, int>::iterator numberHashIter = numberHash.find(queries[i][1]);
            if(numberHashIter != numberHash.end()){
                int count = numberHashIter->second;
                numberHash.erase(queries[i][1]);
                numberHash.insert(make_pair(queries[i][1], count + 1));
                countVector[count + 1]++;
                countVector[count]--;
            }
            else{
                numberHash.insert(make_pair(queries[i][1], 1));
                countVector[1]++;
            }
        }
        else if(queries[i][0] == 2){
            unordered_map<int, int>::iterator numberHashIter = numberHash.find(queries[i][1]);
            if(numberHashIter != numberHash.end()){
                int count = numberHashIter->second;
                numberHash.erase(queries[i][1]);
                if(count - 1 > 0){
                    numberHash.insert(make_pair(queries[i][1], count - 1));
                    countVector[count - 1] ++;
                }
                else{
                    numberHash.erase(queries[i][1]);
                }
                countVector[count]--;
            }
        }
        else{
            if(queries[i][1] < queries.size() && countVector[queries[i][1]] > 0){
                answer.push_back(1);
            }
            else{
                answer.push_back(0);
            }
        }
    }
    return answer;
}