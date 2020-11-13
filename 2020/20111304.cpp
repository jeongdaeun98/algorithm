//N-queen
#include <iostream>
using namespace std;
int dart[15],n, answer = 0;
bool isNqueen(int y){
    for(int i = 0; i < y; i++){
        if(dart[i] == dart[y]) return false;
        if(dart[i] - dart[y] == i - y) return false;
        if(dart[y] - dart[i] == i - y) return false;
    }
    return true;
}
void dfs(int target, int y){
    if(target == n){
        answer++;
        return;
    }
    for(int x = 0; x < n; x++){
        dart[y] = x;
        if(isNqueen(y)) {
            dfs(target + 1, y + 1);
        }
        else dart[y] = 0;
     }
}

int main(void){
    cin >> n;
    dfs(0, 0);
    cout << answer;
}