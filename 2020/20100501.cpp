#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;
queue<int>* getDollQ(vector<vector<int>> board){
    queue<int> *dollQ = new queue<int>[board.size()];
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == 0) continue;
            else dollQ[j].push(board[i][j]);
        }
    }
    return dollQ;
}
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    queue<int>* dollQ = getDollQ(board);
    for(int i = 0; i < moves.size(); i++){
        if(!dollQ[moves[i] - 1].empty()){
            if(!basket.empty() && basket.top() == dollQ[moves[i] - 1].front()){
                basket.pop();
                answer += 2;
            }
            else {
                basket.push(dollQ[moves[i] - 1].front());
            }
            dollQ[moves[i] - 1].pop();
        }
    }
    
    return answer;
}