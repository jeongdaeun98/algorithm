#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(string dirs)
{
	int direct[] = { 1,-1 };
	vector<string> path;
	int dx = 0, dy = 0;
	for (int i = 0; i < dirs.size(); i++) {
		bool changetrue = false;
		string node = "";
		node.append(to_string(dx));
		node.append(to_string(dy));
		if (dx <= 5 && dx >= -5 && dy <= 5 && dy >= -5) {
			if (dirs[i] == 'U' && dy != 5) {
				dy += direct[0];
				changetrue = true;
			}
			else if (dirs[i] == 'D' && dy != -5) {
				dy += direct[1];
				changetrue = true;
			}
			else if (dirs[i] == 'L' && dx != -5) {
				dx += direct[1];
				changetrue = true;
			}
			else if (dirs[i] == 'R' && dx != 5) {
				dx += direct[0];
				changetrue = true;
			}
			if (changetrue) {
				string nodetwo;
				nodetwo.append(to_string(dx));
				nodetwo.append(to_string(dy));
				nodetwo.append(node);
				node.append(to_string(dx));
				node.append(to_string(dy));
				if (!path.empty()) {
					if (find(path.begin(), path.end(), node) == path.end() && find(path.begin(), path.end(), nodetwo) == path.end())
						path.push_back(node);
				}
				else
					path.push_back(node);
			}
		}
	}
	return path.size();
}