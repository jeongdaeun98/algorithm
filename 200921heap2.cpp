#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector<string> split(string str){
    istringstream ss(str);
    string stringBuffer;
    vector<string> stringVector;
    while (getline(ss, stringBuffer, ' '))
    {
       stringVector.push_back(stringBuffer);
    }
    return stringVector;
}
int returnMinNum(priority_queue<int> &maxHeap){
    stack<int> stack;
    int minNum = 0;
    while(!maxHeap.empty()){
        stack.push(maxHeap.top());
        maxHeap.pop();
    }
    if(!stack.empty()){
        minNum = stack.top();
        stack.pop();
    }
    while(!stack.empty()){
        maxHeap.push(stack.top());
        stack.pop();
    }
    return minNum;
}    

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxHeap;
    for(int i = 0; i < operations.size(); i++){
        vector<string> stringVector = split(operations[i]);
        if(stringVector[0].compare("I") == 0) {
            maxHeap.push(stoi(stringVector[1]));
        }
        else if(stringVector[1].compare("1") == 0){
            if(!maxHeap.empty()) maxHeap.pop();
        }
        else {
         returnMinNum(maxHeap);
        }
    }
    if(!maxHeap.empty()){
    answer.push_back(maxHeap.top());
    answer.push_back(returnMinNum(maxHeap));
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}