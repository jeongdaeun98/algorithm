#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
char wall[1001][1001];
int directX[] = {0,0,1,-1};
int directY[] = {1,-1,0,0};
int weight[1001][1001][2];
void initWall(){
    for(int i = 0; i < n; i++){
        cin >> wall[i];
    }
}
int bfs(){
    queue<tuple<int,int, int> > q;
    q.push(make_tuple(0,0,0));
    weight[0][0][0] = 1;
    while(!q.empty()){
        tuple<int, int, int> node = q.front();
        q.pop();
        if(get<0>(node) == n -1 && get<1>(node) == m -1) return weight[get<0>(node)][get<1>(node)][get<2>(node)];
        for(int i = 0; i < 4; i++){
            int dx = directX[i] + get<0>(node);
            int dy = directY[i] + get<1>(node);
            int w = get<2>(node);
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && weight[dx][dy][w]) continue;
            if(w == 0 && dx >= 0 && dx < n && dy >= 0 && dy < m && wall[dx][dy] == '1'){
                q.push(make_tuple(dx, dy, 1));
                weight[dx][dy][1] = weight[get<0>(node)][get<1>(node)][get<2>(node)] + 1;
            }
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && wall[dx][dy] == '0'){
                q.push(make_tuple(dx,dy,w));
                weight[dx][dy][w] = weight[get<0>(node)][get<1>(node)][get<2>(node)] + 1;
            }
        }
    }
    return -1;
}
int main(void){
    cin >> n >> m;
    initWall();
    cout << bfs();
}