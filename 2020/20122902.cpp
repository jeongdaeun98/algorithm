//낚시왕
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct info{
    int r,c,s,direction,size;
};
int water[101][101];
int directx[] = {0,-1,1,0,0};
int directy[] = {0,0,0,1,-1};
int turn[] = {0,2,1,4,3};
int R,C,m;
unordered_map<int,info> shark;
void moveShark(){
    for(unordered_map<int,info>::iterator i = shark.begin(); i != shark.end();i++){
        int copyS = i->second.s;
        if(i->second.direction >= 3) copyS = copyS%(2*C - 2);
        else copyS = copyS%(2*R - 2);
        int count = 0;
        while(1){
            if(copyS == count) break;
            count++;
            int dx = i->second.r + directx[i->second.direction];
            int dy = i->second.c + directy[i->second.direction];
            if(dx >= 1 && dy >= 1 && dx <= R && dy <= C){
                i->second.r = dx;
                i->second.c = dy;
            }
            else{
                i->second.direction = turn[i->second.direction];
                i->second.r += directx[i->second.direction];
                i->second.c += directy[i->second.direction];
            }
        }
    }
}
void eatShark(){
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            water[i][j] = -1;
        }
    }
    for(unordered_map<int,info>::iterator i = shark.begin(); i != shark.end();){
        int r = i->second.r;
        int c = i->second.c;
        if(water[r][c] != -1 && shark[water[r][c]].size < i->second.size){
            shark.erase(shark.find(water[r][c]));
            water[r][c] = i->first;
        }
        else if(water[r][c] != -1 && shark[water[r][c]].size > i->second.size){
            shark.erase(i++);
            continue;
        }
        else if(water[r][c] == -1){
            water[r][c] = i->first;
        }
        i++;
    }
}
int catchShark(int king){
    for(int i = 1; i <= R; i++){
        if(water[i][king] != -1){
            int size = shark[water[i][king]].size;
            shark.erase(shark.find(water[i][king]));
            return size;
        }
    }
    return 0;
}
void print(){
    cout << "\n";
    for(unordered_map<int,info>::iterator i = shark.begin(); i != shark.end(); i++){
        cout << i->second.r << " " << i->second.c << " " << i->second.size << "\n";
    }
}
int main(void){
    cin >> R >> C >> m;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            water[i][j] = -1;
        }
    }
    for(int i = 0; i < m; i++){
        info info;
        cin >> info.r >> info.c;
        cin >> info.s >> info.direction >> info.size;
        water[info.r][info.c] = info.size;
        shark.insert({info.size,info});
    }
    int king = 0, answer = 0;
    while(king != C){
        king++;
        answer += catchShark(king);
        moveShark();
        eatShark();
    }
    cout << answer;
}