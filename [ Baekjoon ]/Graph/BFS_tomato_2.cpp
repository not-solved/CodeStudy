#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

queue<tuple<int, int, int>> Q;
int map[100][100][100];

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, -1, 1 };

int BFS(int x_max, int y_max, int h_max, int count) {
	int y_temp = 0;
	int x_temp = 0;
	int h_temp = 0;
	int nx, ny, nh;
	int day = 0;
	int remain = count;
	while (!Q.empty()) {
		y_temp = get<0>(Q.front());
		x_temp = get<1>(Q.front());
		h_temp = get<2>(Q.front());
		day = map[y_temp][x_temp][h_temp];
		Q.pop();

		for (int i = 0; i < 6; i++) {
			nx = x_temp + dx[i];
			ny = y_temp + dy[i];
			nh = h_temp + dh[i];

			if (ny < 0 || ny > y_max - 1 || nx < 0 || nx > x_max - 1 || nh < 0 || nh > h_max - 1)
				continue;
			if (map[ny][nx][nh] == 0) {
				Q.push(make_tuple(ny, nx, nh));
				map[ny][nx][nh] = day + 1;
				remain--;
			}
		}
	}
	if (remain > 0)
		return -1;
	else
		return day - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y, h;
	cin >> x >> y >> h;
	int count = 0;

	for (int height = 0; height < h; height++) {
		for (int vertical = 0; vertical < y; vertical++) {
			for (int horizon = 0; horizon < x; horizon++) {
				cin >> map[vertical][horizon][height];
				if (map[vertical][horizon][height] == 1)
					Q.push(make_tuple(vertical, horizon, height));
				else if (map[vertical][horizon][height] == 0)
					count++;
			}
		}
	}
	cout << BFS(x, y, h, count);
	return 0;
}