#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[101][101];
bool visited[101][101];
int x_index[4] = { 0, 0, -1, 1 };
int y_index[4] = { -1, 1, 0, 0 };

int flood(int height, int size) {
	memset(visited, 0, sizeof(visited));
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[i][j] > height && !visited[i][j]) {
				count++;
				visited[i][j] = true;
				queue<pair<int, int>> Q;
				Q.push(make_pair(i, j));
				while (!Q.empty()) {
					int yy = Q.front().first;
					int xx = Q.front().second;
					Q.pop();
					if (map[yy + 1][xx] > height && !visited[yy + 1][xx] && yy + 1 < size) {
						visited[yy + 1][xx] = true;
						Q.push(make_pair(yy + 1, xx));
					}
					if (map[yy - 1][xx] > height && !visited[yy - 1][xx] && yy > 0) {
						visited[yy - 1][xx] = true;
						Q.push(make_pair(yy - 1, xx));
					}
					if (map[yy][xx + 1] > height && !visited[yy][xx + 1] && xx + 1 < size) {
						visited[yy][xx + 1] = true;
						Q.push(make_pair(yy, xx + 1));
					}
					if (map[yy][xx - 1] > height && !visited[yy][xx - 1] && xx > 0) {
						visited[yy][xx - 1] = true;
						Q.push(make_pair(yy, xx - 1));
					}
				}
			}
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int size;
	cin >> size;
	int max = 0;
	int min = 100;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> map[i][j];
			if (max < map[i][j])
				max = map[i][j];
			if (min > map[i][j])
				min = map[i][j];
		}
	}
	int result = 0;
	for (int i = min - 1; i <= max; i++) {
		int temp = flood(i, size);
		if (result < temp)
			result = temp;
	}
	cout << result << '\n';
	return 0;
}