#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int i;
    for(i = 0; i < A.size(); i++){
        if(A[i] != i + 1)
            return A[i] - 1;
    }
    if(A.size() == 0) return 1;
    return A[i - 1] + 1;
}
