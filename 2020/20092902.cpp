#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int count = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] < i + 1){
            while(A[i] != i + 1){
                A[i]++;
                if(count + 1 > 1000000000) return -1;
                count++;
            }
        }
        else if(A[i] > i + 1){
            while(A[i] != i + 1){
                A[i]--;
                if(count + 1 > 1000000000) return -1;
                count++;
            }
        }
    }
    return count;
}
