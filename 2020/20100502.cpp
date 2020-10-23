#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    unordered_map<int, bool> numberHash; 
    vector<int> answer;
    for(int i = 0; i < numbers.size(); i++){
        for(int j = i + 1; j < numbers.size(); j++){
            if(numberHash.find(numbers[i] + numbers[j]) == numberHash.end()){
                numberHash.insert(make_pair(numbers[i] + numbers[j], true));
                answer.push_back(numbers[i] + numbers[j]);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}