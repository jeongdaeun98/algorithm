#include <string>
#include <vector>
using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    vector<int> strVector(26);
    int size = s.size();
    for(int i = 0; i < size; i++){
        strVector[s[i] - 'a']++;
    }
    int minNum = 987654321;
    bool isOneTrue = false;
    int count = 0;
    for(int i = 0; i < 26; i++){
        if(strVector[i] == 0) continue;
        if(!isOneTrue && strVector[i] == 1){
            isOneTrue = true;
            count++;
            strVector.erase(strVector.begin() + i);
            i--;
        }
        else if(minNum > strVector[i]) minNum = strVector[i];
    }
    for(int num: strVector){
        if(num == 0) continue;
        while(num > 0 && minNum != num){
            num--;
            count++;
        }
    }
    if(count == 1 || count == 0) return "YES";
    else return "NO";
}