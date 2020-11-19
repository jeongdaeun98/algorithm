//스도쿠
#include <iostream>
using namespace std;

int sudoku[10][10];
bool row[10][10];
bool column[10][10];
bool square[10][10];
void dfs(int count){
    if(count == 81){
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j++){
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
        exit(0);
    }
    int y = count / 9;
    int x = count % 9;
    if(sudoku[y][x] == 0){
        for(int i = 1; i <= 9; i++){
            if(!row[y][i]&& !column[x][i] && !square[(y/3)*3 + x/3][i]){
                sudoku[y][x] = i;
                row[y][i] = true;
                column[x][i] = true;
                square[(y/3)*3 + x/3][i] = true;
                dfs(count + 1);
                sudoku[y][x] = 0;
                row[y][i] = false;
                column[x][i] = false;
                square[(y/3)*3 + x/3][i] = false;
            }
        }
    }
    else{
        dfs(count + 1);
    }
    
}
int main(void){
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] != 0){
                row[i][sudoku[i][j]] = true;
                column[j][sudoku[i][j]] = true;
                square[(i/3)*3 + j/3][sudoku[i][j]] = true;
            }
        }
    }
    dfs(0);
}