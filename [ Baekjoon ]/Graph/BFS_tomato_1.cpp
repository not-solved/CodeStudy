#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX	1000
using namespace std;

queue<pair<int, int>> Q;
queue<int> D;
bool visited[MAX + 1][MAX + 1];
int map[MAX][MAX];

int BFS(int x_max, int y_max, int count) {
	int x_temp = 0;
	int y_temp = 0;
	int day = 0;
	int remain = count;
	while (!Q.empty()) {
		x_temp = Q.front().second;
		y_temp = Q.front().first;
		day = D.front();
		Q.pop();
		D.pop();
		if (map[y_temp + 1][x_temp] == 0 && visited[y_temp + 1][x_temp] == false && y_temp + 1 <= y_max) {
			Q.push(make_pair(y_temp + 1, x_temp));
			D.push(day + 1);
			visited[y_temp + 1][x_temp] = true;
			remain--;
		}
		if (map[y_temp][x_temp + 1] == 0 && visited[y_temp][x_temp + 1] == false && x_temp + 1 <= x_max) {
			Q.push(make_pair(y_temp, x_temp + 1));
			D.push(day + 1);
			visited[y_temp][x_temp + 1] = true;
			remain--;
		}
		if (map[y_temp - 1][x_temp] == 0 && visited[y_temp - 1][x_temp] == false && y_temp - 1 >= 0) {
			Q.push(make_pair(y_temp - 1, x_temp));
			D.push(day + 1);
			visited[y_temp - 1][x_temp] = true;
			remain--;
		}
		if (map[y_temp][x_temp - 1] == 0 && visited[y_temp][x_temp - 1] == false && x_temp - 1 >= 0) {
			Q.push(make_pair(y_temp, x_temp - 1));
			D.push(day + 1);
			visited[y_temp][x_temp - 1] = true;
			remain--;
		}
	}
	if (remain > 0)
		return -1;
	else
		return day;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> x >> y;
	int count = 0;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				Q.push(make_pair(i, j));
				D.push(0);
				visited[i][j] = true;
			}
			else if (map[i][j] == 0)
				count++;
		}
	}

	cout << BFS(x - 1, y - 1, count);
	return 0;
}