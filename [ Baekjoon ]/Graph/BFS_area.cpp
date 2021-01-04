#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[101][101];
int visited[101][101];

int BFS(int y_max, int x_max, int y_input, int x_input) {
	visited[y_input][x_input] = true;
	queue<pair<int, int>> Q;
	Q.push(make_pair(y_input, x_input));
	int area = 1;
	while (!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			if (map[y + 1][x] == 0 && !visited[y + 1][x] && y + 1 < y_max) {
				area++;
				visited[y + 1][x] = true;
				Q.push(make_pair(y + 1, x));
			}
			if (map[y - 1][x] == 0 && !visited[y - 1][x] && y > 0) {
				area++;
				visited[y - 1][x] = true;
				Q.push(make_pair(y - 1, x));
			}
			if (map[y][x + 1] == 0 && !visited[y][x + 1] && x + 1 < x_max) {
				area++;
				visited[y][x + 1] = true;
				Q.push(make_pair(y, x + 1));
			}
			if (map[y][x - 1] == 0 && !visited[y][x - 1] && x > 0) {
				area++;
				visited[y][x - 1] = true;
				Q.push(make_pair(y, x - 1));
			}
		}
	}
	return area;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(map, 0, sizeof(map));
	int n, m, k, x1, x2, y1, y2;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int a = y1; a < y2; a++)
			for (int b = x1; b < x2; b++)
				map[a][b] = 1;
	}
	int count = 0;
	priority_queue<int, vector<int>, greater<int>> area;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && !visited[i][j]) {
				count++;
				int temp = BFS(n, m, i, j);
				area.push(temp);
			}
		}
	}
	cout << count << "\n";
	while (!area.empty()) {
		cout << area.top() << " ";
		area.pop();
	}
	return 0;
}