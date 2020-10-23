#include <iostream>
#include <queue>

using namespace std;

int main(void){
    int num;
    cin >> num;
    queue<int> q;
    for(int i = 1; i <= num; i++){
        q.push(i);
    }
    int remainder;
    while(!q.empty()){
        if(q.size() == 1) remainder = q.front();
        q.pop();
        if(q.size() == 1) remainder = q.front();
        q.push(q.front());
        q.pop();
    }
    cout << remainder;
}