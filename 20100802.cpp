#include <vector>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    vector<int> up(arr.size());
    vector<int> down(arr.size());
    up[0] = 1;
    long sum = 0;
    down[arr.size() - 1] = 1;
    for(int i = 1; i < arr.size(); i++){
        up[i] = arr[i - 1] < arr[i] ? up[i - 1] + 1 : 1;
    }
    for(int i = arr.size() - 2; i >= 0; i--){
        int num = arr[i + 1] < arr[i] ? down[i + 1] + 1 : 1;
        down[i] = max(down[i], num);
    }
    for(int i=0; i<arr.size(); i++) {
            sum += max(up[i], down[i]);
        }
        
        return sum;
}