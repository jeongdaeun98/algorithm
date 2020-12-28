//미세먼지 안녕!
#include <iostream>
#include <vector>
using namespace std;

pair<int,int> direct[] = {{0,1},{0, -1}, {1,0}, {-1, 0}};
int vertex[50][50];
pair<int,int> cleanMachineUp = {-1,-1};
pair<int,int> cleanMachineDown = {-1,-1};
int r, c, t;
vector<pair<int,int>> getDirection(int x, int y){
    vector<pair<int,int>> directionVector;
    for(int i = 0; i < 4; i++){
        int dx = x + direct[i].first;
        int dy = y + direct[i].second;
        if(dx < r && dy < c && dx >= 0 && dy >= 0){
            if(dx == cleanMachineDown.first && dy == cleanMachineDown.second)continue;
            if(dx == cleanMachineUp.first && dy == cleanMachineUp.second) continue;
            directionVector.push_back({dx,dy});
        }
    }
    return directionVector;
}
void moveDown(int up, int dp, int y){
    for(int i = dp; i >= up; i--){
        vertex[i + 1][y] = vertex[i][y];
    }
}
void moveLeft(int lp, int rp, int x){
    for(int i = lp; i < rp - 1; i++){
        vertex[x][i] = vertex[x][i + 1];
    }
}
void moveRight(int rp, int lp, int x){
    for(int i = rp; i > lp; i--){
        vertex[x][i + 1] = vertex[x][i];
    }
}
void moveUp(int up, int dp, int y){
    for(int i = up; i < dp; i++){
        vertex[i][y] = vertex[i + 1][y];
    }
}
void clean(){
    moveDown(0,cleanMachineUp.first - 2,cleanMachineUp.second);
    moveLeft(cleanMachineUp.second, c, 0);
    moveUp(0, cleanMachineUp.first, c - 1);
    moveRight(c - 2, cleanMachineUp.second, cleanMachineUp.first);
    vertex[cleanMachineUp.first][cleanMachineUp.second + 1] = 0;
    moveUp(cleanMachineDown.first + 1, r - 1, cleanMachineDown.second);
    moveLeft(cleanMachineDown.second, c, r - 1);
    moveDown(cleanMachineDown.first, r - 2, c -1);
    moveRight(c - 2, cleanMachineDown.second, cleanMachineDown.first);
    vertex[cleanMachineDown.first][cleanMachineDown.second + 1] = 0;
}
void expand(){
    int spreadNum = 0;
    int weight[50][50];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            weight[i][j] = 0;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(i == cleanMachineDown.first && j == cleanMachineDown.second) continue;
            if(i == cleanMachineUp.first && j == cleanMachineUp.second) continue;
            if(vertex[i][j] != 0){
                spreadNum = vertex[i][j] / 5;
                vector<pair<int,int>> directionVector = getDirection(i,j);
                for(int k = 0; k < directionVector.size(); k++){
                    weight[directionVector[k].first][directionVector[k].second] += spreadNum;
                    weight[i][j] -= spreadNum;
                }
            }
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            vertex[i][j] += weight[i][j];
        }
    }
}
void print(){
    cout << "\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << vertex[i][j] << " ";
        }
        cout << "\n";
    }
}

int getAnswer(){
    int answer = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(vertex[i][j] >= 1)
                answer += vertex[i][j];
            }
        }
    return answer;
}
int main(void){
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> vertex[i][j];
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(vertex[i][j] == -1 && vertex[i+1][j] == -1){
                cleanMachineUp = {i,j};
                cleanMachineDown = {i+1, j};
            }
        }
    }
    for(int i = 0; i < t; i++){
        expand();
        //print();
        clean();
        //print();
    }
    cout << getAnswer();
}