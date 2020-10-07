#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int answer = 0;
    unordered_map<string, int> sherlockHash;
    for(int i = 0; i < s.size(); i++){
        string compareStr;
        for(int j = i; j< s.size(); j++){
            compareStr += s[j];
            sort(compareStr.begin(), compareStr.end());
            unordered_map<string, int>::iterator sherlockHashIter = sherlockHash.find(compareStr);
            if(sherlockHashIter != sherlockHash.end()){
                int count = sherlockHashIter->second;
                answer += count;
                sherlockHash.erase(compareStr);
                sherlockHash.insert(make_pair(compareStr, count + 1));
            }
            else {
                sherlockHash.insert(make_pair(compareStr, 1));
            }
        }
    }
    return answer;
}