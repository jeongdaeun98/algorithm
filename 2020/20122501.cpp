//사다리 조작
#include <iostream>
#include <vector>
using namespace std;

struct width{
    int a,b;
};
struct ladder{
    width w;
    int number,pnumber;
};
int minNum = 5;
vector<ladder> ladderVector;
vector<width> widthVector;
int n,m,h;
bool visited[31][10];
void move(int index){
    while(1){
        bool isMovable = false;
        int pnumber = ladderVector[index].pnumber;
        int number = ladderVector[index].number;
        int laddera = ladderVector[index].w.a;
        int ladderb = ladderVector[index].w.b;
        int minA = h;
        int minB = 0;
        for(int i = 0; i < widthVector.size(); i++){
            int a = widthVector[i].a;
            int b = widthVector[i].b;
            if((pnumber == b || pnumber - 1 == b) && laddera < a && a <= minA){
                if(laddera == a && ladderb == b) continue;
                minA = a;
                minB = b;
                isMovable = true;
            }
        }
        if(isMovable){
            if(pnumber == minB){
                    ladderVector[index].pnumber = minB + 1;
            }
            else{
                ladderVector[index].pnumber = minB;
            }
                ladderVector[index].w.a = minA;
                ladderVector[index].w.b = minB;
        }
        else break;
    }
}
void allLadderMove(){
    for(int i = 0; i < n; i++){
        move(i);
    }
}
bool allLadderCheckSame(){
    for(int i = 0; i < n; i++){
        if(ladderVector[i].number != ladderVector[i].pnumber){
            return false;
        }
    }
    return true;
}
void allLadderInit(){
    for(int i = 0; i < n; i++){
        ladderVector[i].pnumber = ladderVector[i].number;
        ladderVector[i].w.a = 0;
        ladderVector[i].w.b = 0;
    }
}
void dfs(int count, int index){
    if(count > 3){
        return;
    }
    for(int i = index; i < n; i++){
        for(int j = 1; j <= h; j++){
            if(visited[j][i]) continue;
            if(i - 1  > 1 && visited[j][i - 1]) continue;
            if(i + 1 < n && visited[j][i + 1]== true) continue;
            visited[j][i] = true;
                width w;
                w.a = j; w.b = i;
                widthVector.push_back(w);
                allLadderMove();
                if(allLadderCheckSame()){
                    minNum = min(minNum,count);
                }
                allLadderInit();
                dfs(count + 1,i);
                widthVector.pop_back();
                visited[j][i] = false;
        }
    }
}
int main(void){
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        width w;
        cin >> w.a >> w.b;
        widthVector.push_back(w);
        visited[w.a][w.b] = true;
    }
    for(int i = 1; i <= n; i++){
        ladder l;
        l.number = l.pnumber = i;
        l.w.a = l.w.b = 0;
        ladderVector.push_back(l);
    }
    allLadderMove();
    if(allLadderCheckSame()){
        cout << 0;
    }
    else{
        allLadderInit();
        dfs(1, 1);
        if(minNum == 5) cout << -1;
        else cout << minNum;
    }
}