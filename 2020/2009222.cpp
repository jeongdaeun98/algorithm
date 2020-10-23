#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;
vector<bool> visitedVector;
vector<int> candidateVector;
void removeDuplicateCandidate(string numStr){
    int num = stoi(numStr);
    if(num != 1 && num != 0 && find(candidateVector.begin(), candidateVector.end(), num) == candidateVector.end()){
        candidateVector.push_back(stoi(numStr));
    }
}
void makeNumber(vector<int> numberVector, string numStr, int size){
    if(size == 0){
        removeDuplicateCandidate(numStr);
        return;
    }
    for(int i = 0; i < numberVector.size(); i++){
        if(visitedVector[i]) continue;
        visitedVector[i] = true;
        makeNumber(numberVector, numStr+to_string(numberVector[i]), size-1);
        visitedVector[i] = false;
    }
}
int getPrimeCount(){
    int count = 0, isPrime = true;
    for(int i = 0; i < candidateVector.size(); i++){
        for(int j = 2; j <= sqrt(candidateVector[i]); j++){
            if(candidateVector[i]%j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) count++;
        isPrime = true;
    }
    return count;
}
int solution(string numbers) {
    vector<int> numberVector;
    for(int i = 0; i < numbers.length(); i++){
        numberVector.push_back(numbers[i]-'0');
        visitedVector.push_back(false);
    }
    for(int i = 1; i <= numbers.size(); i++){
        makeNumber(numberVector, "", i);
    }
    
    return getPrimeCount();
}