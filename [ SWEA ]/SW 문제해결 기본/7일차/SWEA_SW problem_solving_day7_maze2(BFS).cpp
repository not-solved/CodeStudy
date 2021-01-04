#include <iostream>
#include <queue>
using namespace std;

char maze[100][100];

void BFS(int y, int x) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(y, x));
	maze[y][x] = '5';
	int y_temp = y;
	int x_temp = x;
	while (!Q.empty()) {
		y_temp = Q.front().first;
		x_temp = Q.front().second;
		Q.pop();
		if ((maze[y_temp + 1][x_temp] == '0' || maze[y_temp + 1][x_temp] == '3')
			&& y_temp < 98) {
			Q.push(make_pair(y_temp + 1, x_temp));
			maze[y_temp + 1][x_temp] = '5';
		}
		if ((maze[y_temp - 1][x_temp] == '0' || maze[y_temp - 1][x_temp] == '3')
			&& y_temp > 0) {
			Q.push(make_pair(y_temp - 1, x_temp));
			maze[y_temp - 1][x_temp] = '5';
		}
		if (maze[y_temp][x_temp + 1] == '0' || maze[y_temp][x_temp + 1] == '3'
			&& x_temp < 98) {
			Q.push(make_pair(y_temp, x_temp + 1));
			maze[y_temp][x_temp + 1] = '5';
		}
		if ((maze[y_temp][x_temp - 1] == '0' || maze[y_temp][x_temp - 1] == '3')
			&& x_temp > 0) {
			Q.push(make_pair(y_temp, x_temp - 1));
			maze[y_temp][x_temp - 1] = '5';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int a = 1; a <= 10; a++) {
		int loop;
		cin >> loop;
		int start_x, start_y, terminate_x, terminate_y;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> maze[i][j];

				if (maze[i][j] == '2') {
					start_x = j;
					start_y = i;
				}
				else if (maze[i][j] == '3') {
					terminate_x = j;
					terminate_y = i;
				}
			}
		}
		BFS(start_y, start_x);
		bool find = (maze[terminate_y][terminate_x] == '5' ? true : false);
		cout << "#" << loop << " " << find << "\n";
	}
	return 0;
}