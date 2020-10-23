#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;

int solution(vector<int> &A) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int comparedNum = 0;
    int comparingNum = 0;
    for(int i = 0; i < A.size(); i++){
        comparedNum += A[i];
    }
    for(int i = A.size() - 1; i > 0; i--){
        comparingNum += A[i];
        comparedNum -= A[i];
        pq.push(make_pair(abs(comparedNum - comparingNum), i));
    }
    return pq.top().first;
}
