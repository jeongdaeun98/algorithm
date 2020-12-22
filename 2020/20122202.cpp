//로봇 청소기
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int vertex[50][50];
int directx[] = {-1,0,1,0};
int directy[] = {0,1,0,-1};
int n,m;
int turnDirection(int pd){
    int direction;
    switch(pd){
        case 0:
        return 3;
        case 1:
        return 0;
        case 2:
        return 1;
        default:
        return 2;
    }
}
int backDirection(int pd){
    switch(pd){
        case 0:
        return 2;
        case 1:
        return 3;
        case 2:
        return 0;
        default:
        return 1;
    }
}
int bfs(int x, int y, int d){
    queue<tuple<int,int,int>> q;
    q.push({x,y,d});
    vertex[x][y] = 2;
    int answer = 1;
    while(!q.empty()){
        bool isBlocked = true;
        tuple<int,int,int> node = q.front();
        q.pop();
        int direction = get<2>(node);
        for(int i = 0; i < 4; i++){
            direction = turnDirection(direction);
            int dx = directx[direction] + get<0>(node);
            int dy = directy[direction] + get<1>(node);
            if(dx < n && dx >= 0 && dy < m && dy >= 0 && vertex[dx][dy] == 0){
                answer++;
                vertex[dx][dy] = 2;
                isBlocked = false;
                q.push({dx,dy,direction});
                break;
            }
        }
        if(isBlocked){
            int direction = backDirection(get<2>(node));
            int dx = directx[direction] + get<0>(node);
            int dy = directy[direction] + get<1>(node);
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && (vertex[dx][dy] == 2 || vertex[dx][dy] == 0)){
                q.push({dx,dy,get<2>(node)});
            }
        }
    }
    return answer;
}
int main(void){
    cin >> n >> m;
    int x, y, d;
    cin >> x >> y >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           cin >> vertex[i][j];
        }
    }
    cout << bfs(x,y,d);
}