//줄세우기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> student[32001];
int degree[32001] = {0};
void topologySort(int n){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    for(int i = 1; i <= n; i++){
        int x = q.front();
        cout << x << " ";
        q.pop();
        for(int j = 0; j < student[x].size(); j++){
            if(--degree[student[x][j]] == 0){
                q.push(student[x][j]);
            }
        }
    }
}
int main(void){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int num1, num2;
        cin >> num1 >> num2;
        student[num1].push_back(num2);
        degree[num2]++;
    }
    topologySort(n);

}