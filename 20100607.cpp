#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void minimumBribes(vector<int> q) {
    int bribes = 0;
    for(int i = q.size() - 1; i >= 0; i--){
        if(q[i] - (i + 1) > 2){
            cout << "Too chaotic\n";
            return;
        }
        else{
            for(int j = max(0, q[i] - 2); j < i; j++){
                if(q[j] > q[i]) bribes++;
            }
        }
    }
    cout << bribes << "\n";
}