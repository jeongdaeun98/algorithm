#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string arrangement) {
    queue<char> q;
    int answer = 0;
    for(char ch : arrangement){
        q.push(ch);
    }
    int num = 0;
    char presentChar = '0';
    while(!q.empty()){
        if(q.front() == '('){
            num++;
        }
        else if(presentChar == '(' && q.front() == ')'){
            num--;
            answer += num;
        }
        else if(q.front() == ')'){
            num--;
            answer++;
        }
        presentChar = q.front();
        q.pop();
    }
    return answer;
}