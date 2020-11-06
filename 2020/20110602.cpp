//사탕 게임
#include <iostream>
#include <string>
using namespace std;

int directx[] = {0,0,1,-1};
int directy[] = {1,-1,0,0};
string candy[51];
int n, ans = 0;
void swap(int x1, int x2, int y1, int y2){
    char temp = candy[y1][x1];
    candy[y1][x1] = candy[y2][x2];
    candy[y2][x2] = temp;
}
void check(int y, int x){
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (candy[i][j] == candy[i][j - 1]) {
                ++cnt;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
    }
 
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (candy[j][i] == candy[j - 1][i]) {
                ++cnt;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
    }
}
int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> candy[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 4; k++){
                int dx = directx[k] + j;
                int dy = directy[k] + i;
                if(dx >= 0 && dx < n && dy >= 0 && dy < n){
                    swap(dx,j, dy, i);
                    check(i,j);
                    check(dy, dx);
                    swap(dx,j, dy, i);
                }
            }
        }
    }
    cout << ans;

}