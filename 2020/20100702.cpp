#include <unordered_map>
#include <string>
using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    unordered_map<char, bool> sameCharHash;
    int s1Size = s1.size();
    for(int i = 0; i < s1Size; i++){
        unordered_map<char, bool>::iterator sameCharHashIter = sameCharHash.find(s1[i]);
        if(sameCharHashIter == sameCharHash.end()){
            sameCharHash.insert(make_pair(s1[i],true));
        }
    }
    bool sameTrue = false;
    int s2Size = s2.size();
    for(int i = 0; i < s2Size; i++){
        if(sameCharHash.find(s2[i]) != sameCharHash.end()){
            sameTrue = true;
        }
    }
    if(sameTrue) return "YES";
    else return "NO";
}