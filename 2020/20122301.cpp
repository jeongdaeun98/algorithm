//스타트와 링크
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int num,minNum = 987654321;
int real[20][20];
int totalNum(vector<int> numVector){
    int sum = 0;
    for(int i = 0; i < numVector.size(); i++){
        for(int j = 0; j < numVector.size(); j++){
            if(i == j) continue;
            sum += real[numVector[i]][numVector[j]];
        }
    }
    return sum;
}
void dfs(int index,vector<int> startVector, vector<int> linkVector){
    if(index == num){
        if(startVector.size() == num/2 && linkVector.size() == num/2){
            int startTotal = totalNum(startVector);
            int linkTotal = totalNum(linkVector);
            minNum = min(abs(startTotal - linkTotal), minNum); 
        }
        return;
    }
        startVector.push_back(index);
        dfs(index + 1,startVector,linkVector);
        startVector.pop_back();
        linkVector.push_back(index);
        dfs(index + 1,startVector, linkVector);
        linkVector.pop_back();
    
}
int main(void){
    cin >> num;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            cin >> real[i][j];
        }
    }
    vector<int> startVector, linkVector;
    dfs(0,startVector, linkVector);
    cout << minNum;
}