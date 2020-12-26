//드래곤 커브
#include <iostream>
#include <vector>
using namespace std;

struct point{
    int x,y,direction;
};
pair<int,int> direct[]={{1,0},{0,-1},{-1,0},{0,1}};
int rotationDirect[]={1,2,3,0};
bool visitedPoint[102][102];
int answer = 0;
void upgradeGeneration(point p, int generation){
    int pgeneration = 0;
    vector<point> pointVector;
    point end;
    end.x = p.x + direct[p.direction].first;
    end.y = p.y + direct[p.direction].second;
    end.direction = p.direction;
    visitedPoint[end.x][end.y] = true;
    pointVector.push_back(end);
    while(pgeneration != generation){
        int size = pointVector.size();
        pgeneration++;
        for(int i = size - 1; i >= 0; i--){
            end.direction = rotationDirect[pointVector[i].direction];
            pointVector.push_back(end);
        }
        for(int i = size; i < pointVector.size(); i++){
            pointVector[i].x = pointVector[i - 1].x + direct[pointVector[i].direction].first;
            pointVector[i].y = pointVector[i - 1].y + direct[pointVector[i].direction].second;
            visitedPoint[pointVector[i].x][pointVector[i].y] = true;
        }
    }
}
void checkSquare(){
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            if(visitedPoint[i][j] == true && visitedPoint[i + 1][j + 1] == true && visitedPoint[i+1][j] == true && visitedPoint[i][j + 1] == true){
                answer++;
            }
        }
    }
}
int main(void){
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        point p;
        int generation;
        cin >> p.x >> p.y >> p.direction >> generation;
        visitedPoint[p.x][p.y] = true;
        upgradeGeneration(p,generation);
    }
    checkSquare();
    cout << answer;
}