#include <iostream>
#include <queue>
using namespace std;

// 최대힙
int main(void){
    long long count, num;
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> count;
    priority_queue<long long, vector<long long>, less<long long>> pq;
    for(int i = 0; i < count; i++){
        cin >> num;
        if(num == 0 && !pq.empty()){
            cout << pq.top() << "\n";
            pq.pop();
        }
        else if(num == 0 && pq.empty()){
            cout << 0 << "\n";
        }
        else{
            pq.push(num);
        }
    }
}