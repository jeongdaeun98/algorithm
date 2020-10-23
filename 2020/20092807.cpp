#include <iostream>
#include <stack>

using namespace std;

int solution(int N) {
    int num = N;
    bool startTrue = false;
    int maxNum = 0;
    stack<int> stack;
    while(1){
        if(num < 2){
            stack.push(num);
            break;
        }
        stack.push(num % 2);
        num = num / 2;
    }
    int count = 0;
    while(!stack.empty()){
        int stackNum = stack.top();
        if(stackNum == 1){
            if(!startTrue) startTrue = true;
            else if(maxNum < count) maxNum = count;
            count = 0;
        }
        else if(stackNum == 0){
            count ++;
        }
        stack.pop();
    }
    return maxNum;
}

