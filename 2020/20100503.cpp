#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<int> getBinaryStack(int num, int n){
    stack<int> numStack;
    while(1){
        if(num < 2){
            numStack.push(num);
            break;
        }
        numStack.push(num%2);
        num = num / 2;
    }
    while(numStack.size() < n){
        numStack.push(0);
    }
    return numStack;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < arr1.size(); i++){
        int num = arr1[i];
        stack<int> num1Stack = getBinaryStack(num, n);
        num = arr2[i];
        stack<int> num2Stack = getBinaryStack(num, n);
        string answerString = "";
        while(!num1Stack.empty()){
            if(num1Stack.top() == 1 || num2Stack.top() == 1){
                answerString += '#';
            }
            else{
                answerString += ' ';
            }
            num1Stack.pop();
            num2Stack.pop();
        }
        answer.push_back(answerString);
    }
    return answer;
}