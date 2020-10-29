// 암호만들기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char vowelArray[] = {'a','e','i','o','u'};
bool isVowel(char alpha){
    for(int i = 0; i < 5; i++){
        if(alpha == vowelArray[i])
            return true;
    }
    return false;
}
void combination(int vowelCount, int consonantCount, int index, vector<char> alphaVector, vector<char> realVector, int target){
    if(vowelCount >= 1 && consonantCount >= 2 && target == 0){
        for(int i = 0; i < alphaVector.size(); i++){
            cout << alphaVector[i];
        }
        cout << "\n";
        return;
    }
    if(index == realVector.size()){
        return;
    }
    alphaVector.push_back(realVector[index]);
    if(isVowel(realVector[index])){
        combination(vowelCount + 1, consonantCount, index + 1, alphaVector, realVector, target - 1);
    }
    else{
        combination(vowelCount, consonantCount + 1, index + 1, alphaVector, realVector, target - 1);
    }
    alphaVector.pop_back();
    combination(vowelCount, consonantCount, index + 1, alphaVector, realVector, target);
}
int main(void){
    int count, target;
    char alpha;
    cin >> target >> count;
    vector<char>realVector, alphaVector;
    for(int i = 0; i < count; i++){
        cin >> alpha;
        realVector.push_back(alpha);
    }
    sort(realVector.begin(), realVector.end());
    combination(0,0,0,alphaVector,realVector,target);
}