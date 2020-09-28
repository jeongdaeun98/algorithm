#include <iostream>
using namespace std;

bool check[8];
int n,m;
void initCheck(){
    for(int i = 0; i < 8; i++){
        check[i] = false;
    }
}
void dfs(string str, int count){
    if(count == 0){
        cout << str << "\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if(check[i]) continue;
        check[i] = true;
        dfs(str + to_string(i + 1) + " ", count - 1);
        check[i] = false;
    }
}
int main(void){
    cin >> n >> m;
    initCheck();
    dfs("", m);
}