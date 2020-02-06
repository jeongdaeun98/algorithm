#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int personNum;
	cin >> personNum;
	int *score = new int[personNum];
	for (int i = 0; i < personNum; i++)
		score[i] = 0;
	vector<pair<int, int>> person;
	for (int i = 0; i < personNum; i++) {
		pair<int, int> personWeight;
		cin >> personWeight.first;
		cin >> personWeight.second;
		person.push_back(personWeight);
	}
	int personNumber = 0;
	for (pair<int,int> firstPersonWeight : person) {
		for (pair<int,int> secondPersonWeight : person) {
			if (firstPersonWeight.first < secondPersonWeight.first && firstPersonWeight.second < secondPersonWeight.second)
				score[personNumber]++;
		}
		personNumber++;
	}
	for (int i = 0; i < personNum; i++) 
		cout << score[i] + 1 << " ";
	
}