#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;
int primeArray[10000] = {0};
int visited[10];
int depth[10000] = {0};
void initDepth() {
	for (int i = 1000; i < 10000; i++)
		depth[i] = 0;
}
void setPrimeArray() {
	int num = 1000;
	bool primeTrue = true;
	while (1) {
		if (num > 9999) break;
		for (int i = 2; i <= sqrt(num); i++) {
			if (num % i == 0) { 
				primeTrue = false;
				break; 
			}
		}
		if (primeTrue) { primeArray[num] = 1; }
		primeTrue = true;
		num++;
	}
}


void bfs(int first, int second) {
	queue<int> q;
	q.push(first);
	bool breakTrue = false;
	while (!q.empty()) {
		int realnode = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			string node = to_string(realnode);
			for (int j = 0; j <= 9; j++) {
				node[i] = j + '0';
				int newnode = atoi(node.c_str());
				if (newnode >= 1000 &&!depth[newnode] && primeArray[newnode]) {
					if(newnode != realnode)
					depth[newnode] = depth[realnode] + 1;
					if (newnode == second) return;
					q.push(newnode);
				}
			}
			
		}
		 
	}
}
int main(void) {
	int t;
	cin >> t;
	setPrimeArray();
	for (int i = 0; i < t; i++) {
		int first, second;
		cin >> first >> second;
		bfs(first, second);
		if (depth[second] == 0 && first != second) cout << "Impossible" << "\n";
		else cout << depth[second] << "\n";
		initDepth();
	}
	
}