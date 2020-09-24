#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checked[26][26];
int directX[] = {0,0,1,-1};
int directY[] = {1,-1,0,0};
int vertex[26][26];
int personCount = 0;
void init(int num){
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            checked[i][j] = false;
        }
    }
}
void dfs(int x, int y, int num){
    checked[x][y] = true;
    personCount++;
    for(int i = 0; i < 4; i++){
        int dx = directX[i] + x;
        int dy = directY[i] + y;
        if(dx < num && dx >= 0 && dy < num && dy >= 0 && !checked[dx][dy] && vertex[dx][dy] == 1){
            dfs(dx, dy, num);
        }
    }
}
void print(int firstNum, vector<int> secondNumVector){
    cout << firstNum << "\n";
    sort(secondNumVector.begin(), secondNumVector.end());
    for(int i = 0; i < secondNumVector.size(); i++){
       cout << secondNumVector[i] << "\n";
    }
}
void searchDfs(int num){
    int apartCount = 0;
    vector<int> personVector;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(!checked[i][j] && vertex[i][j] == 1){
                personCount = 0;
                apartCount++;
                dfs(i, j, num);
                personVector.push_back(personCount);
            }
        }
    }
    print(apartCount, personVector);
}
int main(void){
    int num;
    cin >> num;
    string house;
    for(int i = 0; i < num; i++){
        cin >> house;
        for(int j= 0; j < house.size(); j++){
            vertex[i][j] = house[j] - '0';
        }
    }
    init(num);
    searchDfs(num);
}