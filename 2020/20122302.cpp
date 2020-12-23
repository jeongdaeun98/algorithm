//경사로
#include <iostream>
using namespace std;

int main(void){
    int n, l, answer = 0;
    cin >> n >> l;
    int vertex[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> vertex[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        pair<int,int> node = {vertex[i][0], 0};
        for(int j = 0; j < n; j++){
            if(node.first == vertex[i][j] || node.first + 1 == vertex[i][j] || node.first - 1 == vertex[i][j]){
                if(node.first == vertex[i][j]){
                    node.second++;
                }
                if(node.first - 1 == vertex[i][j]){
                    if(node.second < 0) break;
                    node.first = vertex[i][j];
                    node.second = -l + 1;
                }
                if(node.first + 1 == vertex[i][j]){
                    if(node.second < l) break;
                    node.first = vertex[i][j];
                    node.second = 1;
                }
                if(j == n - 1 && node.second >= 0){
                    answer++;
                }
            }
            else{
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        pair<int,int> node = {vertex[0][i], 0};
        for(int j = 0; j < n; j++){
            if(node.first == vertex[j][i] || node.first + 1 == vertex[j][i] || node.first - 1 == vertex[j][i]){
                if(node.first == vertex[j][i]){
                    node.second++;
                }
                if(node.first - 1 == vertex[j][i]){
                    if(node.second < 0) break;
                    node.first = vertex[j][i];
                    node.second = -l + 1;
                }
                if(node.first + 1 == vertex[j][i]){
                    if(node.second < l) break;
                    node.first = vertex[j][i];
                    node.second = 1;
                }
                if(j == n - 1 && node.second >= 0){
                    answer++;
                }
            }
            else{
                break;
            }
        }
    }
    cout << answer;
}