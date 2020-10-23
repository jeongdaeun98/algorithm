#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

// 절대값 힙
struct numStruct {
    int num;
};
bool operator < (numStruct a, numStruct b){
    if(abs(a.num) != abs(b.num)) return abs(a.num) > abs(b.num);
    else return a.num > b.num; 
}

int main(void){
    int count, num;
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> count;
    priority_queue<numStruct> pq;
    for(int i = 0; i < count; i++){
        cin >> num;
        if(num == 0 && !pq.empty()){
            cout << pq.top().num << "\n";
            pq.pop();
        }
        else if(num == 0 && pq.empty()){
            cout << 0 << "\n";
        }
        else{
            numStruct object;
            object.num = num;
            pq.push(object);
        }
    }
}