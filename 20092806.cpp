#include <iostream>
using namespace std;
int n, m;
void dfs(int count, string str){
    if(count == 0){
        cout << str << "\n";
        return;
    }
    int start = 0;
    if(str[str.size() - 2] - '0' > 1) start = str[str.size() - 2] - '0' - 1;
    for(int i = start; i < n; i++){
        dfs(count - 1, str + to_string(i + 1) + " ");
    }
}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    dfs(m, "");
}