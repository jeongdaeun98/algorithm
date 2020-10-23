#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int directx[] = {0,0,-1,1};
int directy[] = {1,-1,0,0};
bool visited[11][11];
int areaSize = 0;
void initVisited(int sizeOfMatrix){
	for(int i = 0; i < sizeOfMatrix; i++){
		for(int j = 0; j < sizeOfMatrix; j++){
			visited[i][j] = false;
		}
	}
}
void dfs(int x, int y, int sizeOfMatrix, int **matrix){
	areaSize++;
	visited[x][y] = true;
	for(int i = 0; i < 4; i++){
		int dx = x + directx[i];
		int dy = y + directy[i];
		if(dx >= 0 && dx < sizeOfMatrix && dy >= 0 && dy < sizeOfMatrix && !visited[dx][dy] && matrix[dx][dy] == 1){
			dfs(dx, dy, sizeOfMatrix, matrix);
		}
	}
}
vector<int> searchDfs(int sizeOfMatrix, int **matrix){
	vector<int> areaSizeVector;
	for(int i = 0; i < sizeOfMatrix; i++){
		for(int j = 0; j < sizeOfMatrix; j++){
			if(!visited[i][j] && matrix[i][j] == 1){
				dfs(i,j,sizeOfMatrix, matrix);
			}
			if(areaSize > 0){
			areaSizeVector.push_back(areaSize);
		}
		areaSize = 0;
		}
	}
	return areaSizeVector;
}
void solution(int sizeOfMatrix, int **matrix) {
  // TODO: 이곳에 코드를 작성하세요.
	vector<int> areaSizeVector = searchDfs(sizeOfMatrix, matrix);
	sort(areaSizeVector.begin(), areaSizeVector.end());
		cout << areaSizeVector.size() << "\n";
		for(int i = 0; i < areaSizeVector.size(); i++){
			cout << areaSizeVector[i] << " ";
		}
}
