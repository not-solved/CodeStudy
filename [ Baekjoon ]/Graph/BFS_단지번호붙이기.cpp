#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char map[26][26];
bool visited[26][26];
queue<pair<int, int>> Q;

int BFS(int x, int y, int count) {
	Q.push(make_pair(x, y));
	visited[x][y] = true;
	int result = count;
	while (!Q.empty()) {
		int x_temp = Q.front().first;
		int y_temp = Q.front().second;
		Q.pop();
		result++;
		if (map[x_temp + 1][y_temp] == '1' && visited[x_temp + 1][y_temp] == false) {
			Q.push(make_pair(x_temp + 1, y_temp));
			visited[x_temp + 1][y_temp] = true;
		}
		if (map[x_temp][y_temp + 1] == '1' && visited[x_temp][y_temp + 1] == false) {
			Q.push(make_pair(x_temp, y_temp + 1));
			visited[x_temp][y_temp + 1] = true;
		}
		if (map[x_temp - 1][y_temp] == '1' && visited[x_temp - 1][y_temp] == false) {
			Q.push(make_pair(x_temp - 1, y_temp));
			visited[x_temp - 1][y_temp] = true;
		}
		if (map[x_temp][y_temp - 1] == '1' && visited[x_temp][y_temp - 1] == false) {
			Q.push(make_pair(x_temp, y_temp - 1));
			visited[x_temp][y_temp - 1] = true;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	vector<int> inform;
	int buildings = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && visited[i][j] == false) {
				int count = BFS(i, j, 0);
				inform.push_back(count);
				buildings++;
			}
		}
	}
	sort(inform.begin(), inform.end());
	cout << buildings << "\n";
	for (int i = 0; i < inform.size(); i++)
		cout << inform[i] << "\n";
	return 0;
}