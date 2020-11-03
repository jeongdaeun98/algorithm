//부등호
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> number[10];
int biggestDegree[10] = {0};
int smallestDegree[10] = {0};
int bigAnswer[10], smallAnswer[10];
void biggestTopologySort(int n){
    priority_queue<int> pq;
    int count = 0;
    for(int i = 0; i <= n; i++){
        if(biggestDegree[i] == 0) pq.push(i);
    }
    for(int i = 0; i <= n; i++){
        int num = pq.top();
        pq.pop();
        bigAnswer[num] = count++; 
        for(int j = 0; j < number[num].size(); j++){
            if(--biggestDegree[number[num][j]] == 0){
                pq.push(number[num][j]);
            }
        }
    }
}
void smallestTopologySort(int n){
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i <= n; i++){
        if(smallestDegree[i] == 0) pq.push(i);
    }
    for(int i = 0; i <= n; i++){
        int num = pq.top();
        pq.pop();
        smallAnswer[num] = count++;
        for(int j = 0; j < number[num].size(); j++){
            if(--smallestDegree[number[num][j]] == 0){
                pq.push(number[num][j]);
            }
        }
    }
}
int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char inequalitySign;
        cin >> inequalitySign;
        if(inequalitySign == '>'){
            number[i + 1].push_back(i);
            biggestDegree[i]++;
            smallestDegree[i]++;
        }
        else{
            number[i].push_back(i + 1);
            biggestDegree[i + 1]++;
            smallestDegree[i + 1]++;
        }
    }
    biggestTopologySort(n);
    smallestTopologySort(n);
    for(int i = 0; i <= n; i++){
        cout << bigAnswer[i] + 9 - n;
    }
    cout << "\n";
    for(int i = 0; i <= n; i++){
        cout << smallAnswer[i];
    }
}