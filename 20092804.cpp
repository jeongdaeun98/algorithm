#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string,bool> stringMap;
bool check[8];
int n,m;
void initCheck(){
    for(int i = 0; i < 8; i++){
        check[i] = false;
    }
}
void dfs(string str, int count){
    if(count == 0){
        string copyStr = str;
        sort(copyStr.begin(), copyStr.end());
        if(stringMap.find(copyStr) != stringMap.end()) return;
        stringMap.insert(make_pair(copyStr, true));
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