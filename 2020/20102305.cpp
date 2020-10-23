#include <iostream>
#include <queue>
using namespace std;

int main(void){
    int numberSize, num;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> numberSize;
    priority_queue<int> lowerpq;
    priority_queue<int, vector<int>, greater<int>> higherpq;
    for(int i = 0; i < numberSize; i++){
        cin >> num;
        if(higherpq.size() < lowerpq.size()) higherpq.push(num);
        else lowerpq.push(num);
        if(!lowerpq.empty() && !higherpq.empty() && higherpq.top() < lowerpq.top()){
            int highNum = lowerpq.top();
            int lowNum = higherpq.top();
            lowerpq.pop();
            higherpq.pop();
            higherpq.push(highNum);
            lowerpq.push(lowNum);
        }
        cout << lowerpq.top() << "\n";
    }
}