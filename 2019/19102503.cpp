#include <iostream>
#include <vector>
using namespace std;
int maxnum(int a, int b, int c) {
	if (a <= b && c <= b ) return b;
	if (b <= a && c <= a ) return a;
	if (a <= c && b <= c) return c;
	if (a == b && b == c) return b;
}
int finalmaxnum(int a, int b, int c, int d) {
	if (a <= b && c <= b && d <= b) return b;
	if (b <= a && c <= a && d <= a) return a;
	if (a <= c && b <= c && d <= c) return c;
	if (a <= d && b <= d && c <= d) return d;
	if (a == b && b == c && b== d) return b;
}
int solution(vector<vector<int> > land){
	for (int i = 0; i < land.size() - 1; i++) {
		land[i + 1][0] += maxnum(land[i][1], land[i][2], land[i][3]);
		land[i + 1][1] += maxnum(land[i][0], land[i][2], land[i][3]);
		land[i + 1][2] += maxnum(land[i][0], land[i][1], land[i][3]);
		land[i + 1][3] += maxnum(land[i][0], land[i][1], land[i][2]);
	}
	return finalmaxnum(land[land.size()-1][0], land[land.size() - 1][1], land[land.size() - 1][2], land[land.size() - 1][3]);
}