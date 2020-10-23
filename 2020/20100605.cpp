#include <vector>
using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int answer = -987654321;
    int x[] = {0, 0, 0, 1, 2, 2, 2};
    int y[] = {0, 1, 2, 1, 0, 1, 2};
    bool isBreak = false;
    int n = arr.size();
    int m = arr[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int total = 0;
            for(int k = 0; k < 7; k++){
                int dx = i + x[k];
                int dy = j + y[k];
                if(dx >= 0 && dy >= 0 && dx < n && dy < m){
                    total += arr[dx][dy];
                }
                else {
                    isBreak = true;
                    break;
                }
            }
            if(isBreak){
                isBreak = false;
            }
            else if(answer < total){
                answer = total;
            }
        }
    }
    return answer;
}