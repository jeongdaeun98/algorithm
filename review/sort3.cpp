#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool sorting(int a, int b){
    return a > b ? true : false;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), sorting);
    answer = citations[0];
    while(answer){
        int higherC = 0;
        int lowerC = 0;
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] > answer) higherC++;
            else if(citations[i] < answer) lowerC++;
            else{
                higherC++;
                lowerC++;
            }
        }
        if(higherC >= answer && answer >= lowerC)
            return answer;
        answer--;
    }
    return answer;
}