#include <vector>

using namespace std;

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    vector<int> sum;
    int answer = arr[0];
    int maxNum = arr[0];
    if(arr.size() <= 2) return 0;
    for(int i = 0; i < arr.size(); i++){
        if(i - 2 < 0){
            sum.push_back(arr[i]);
        }
        else{
            maxNum = max(maxNum, sum[i - 2]);
            int num = max(max(arr[i] + maxNum, maxNum), arr[i]);
            if(answer < num) answer = num;
            sum.push_back(num);
        }
    }
    return answer;
}