#include <iostream>
using namespace std;
int n, m;
void dfs(int count, string str){
    if(count == 0){
        cout << str << "\n";
        return;
    }
    for(int i = 0; i < n; i++){
        dfs(count - 1, str + to_string(i + 1) + " ");
    }
}
int main(void){
    cin >> n >> m;
    dfs(m, "");
}