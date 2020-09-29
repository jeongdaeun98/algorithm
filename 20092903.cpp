#include <iostream>
#include <string>
using namespace std;

int solution(string &S) {
    int totalCount = 0;
    int aCount = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'a'){
            aCount++;
        }
        if(aCount > 2){
            totalCount = 0;
            break;
        }
        if(S[i] != 'a'){
            if(aCount < 2){
                totalCount += 2 - aCount;
            }
            aCount = 0;
        }
    }
    if(totalCount == 0 && aCount > 2) return -1;
    if(S[S.size() - 1] != 'a'){
        totalCount += 2;
    }
    else return totalCount;
}
