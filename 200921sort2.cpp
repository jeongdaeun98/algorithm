#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(string a, string b){
    return stoi(a+b) > stoi(b+a);
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNumVector(numbers.size());
    for(int i = 0; i < numbers.size(); i++){
        strNumVector[i] = to_string(numbers[i]);
    }
    sort(strNumVector.begin(), strNumVector.end(), compare);
    for(int i = 0; i < strNumVector.size(); i++){
        answer += strNumVector[i];
    }
    if(answer[0] == '0') answer = "0";
    return answer;
}