#include <iostream>
#include <queue>
#include <tuple>
#define MAX	1000
using namespace std;

queue<tuple<int, int, bool>> Q;
int visited[MAX + 1][MAX + 1][2];
char map[MAX + 1][MAX + 1];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int BFS(int x_dest, int y_dest) {
	int x_temp = 0;
	int y_temp = 0;
	bool destroy = false;
	Q.push(make_tuple(0, 0, false));
	visited[0][0][0] = 1;
	int nx, ny;
	while (!Q.empty()) {
		y_temp = get<0>(Q.front());
		x_temp = get<1>(Q.front());
		destroy = get<2>(Q.front());
		Q.pop();
		if (x_temp == x_dest && y_temp == y_dest) {
			if (visited[y_temp][x_temp][0] && visited[y_temp][x_temp][1])
				return min(visited[y_temp][x_temp][0], visited[y_temp][x_temp][1]);
			else if (visited[y_temp][x_temp][0])
				return visited[y_temp][x_temp][0];
			else
				return visited[y_temp][x_temp][1];
		}
		for (int i = 0; i < 4; i++) {
			nx = x_temp + dx[i];
			ny = y_temp + dy[i];

			if (nx < 0 || nx > x_dest || ny < 0 || ny > y_dest)
				continue;
			if (destroy == false) {
				if (map[ny][nx] == '0' && visited[ny][nx][0] <= 0) {
					Q.push(make_tuple(ny, nx, destroy));
					visited[ny][nx][0] = visited[y_temp][x_temp][0] + 1;
				}
				else if (map[ny][nx] == '1' && visited[ny][nx][1] <= 0) {
					Q.push(make_tuple(ny, nx, true));
					visited[ny][nx][1] = visited[y_temp][x_temp][0] + 1;
				}
			}
			else {
				if (map[ny][nx] == '0' && visited[ny][nx][1] <= 0) {
					Q.push(make_tuple(ny, nx, destroy));
					visited[ny][nx][1] = visited[y_temp][x_temp][1] + 1;
				}
				if (map[ny][nx] == '1')
					continue;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> y >> x;
	int count = 0;
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			cin >> map[i][j];


	cout << BFS(x - 1, y - 1);
	return 0;
}