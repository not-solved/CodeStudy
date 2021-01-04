#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char maze[16][16];
bool visited[16][16];

void BFS(int y, int x) {
	visited[y][x] == true;
	queue<pair<int, int>> Q;
	Q.push(make_pair(y, x));
	int y_temp = y;
	int x_temp = x;
	while (!Q.empty()) {
		y_temp = Q.front().first;
		x_temp = Q.front().second;
		Q.pop();
		if ((maze[y_temp + 1][x_temp] == '0' || maze[y_temp + 1][x_temp] == '3')
			&& !visited[y_temp + 1][x_temp] && y_temp < 15) {
			Q.push(make_pair(y_temp + 1, x_temp));
			visited[y_temp + 1][x_temp] = true;
		}
		if ((maze[y_temp - 1][x_temp] == '0' || maze[y_temp - 1][x_temp] == '3')
			&& !visited[y_temp - 1][x_temp] && y_temp > 0) {
			Q.push(make_pair(y_temp - 1, x_temp));
			visited[y_temp - 1][x_temp] = true;
		}
		if (maze[y_temp][x_temp + 1] == '0' || maze[y_temp][x_temp + 1] == '3'
			&& !visited[y_temp][x_temp + 1] && x_temp < 15) {
			Q.push(make_pair(y_temp, x_temp + 1));
			visited[y_temp][x_temp + 1] = true;
		}
		if ((maze[y_temp][x_temp - 1] == '0' || maze[y_temp][x_temp - 1] == '3')
			&& !visited[y_temp][x_temp - 1] && x_temp > 0) {
			Q.push(make_pair(y_temp, x_temp - 1));
			visited[y_temp][x_temp - 1] = true;
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
		memset(visited, false, sizeof(visited));
		int start_x, start_y, terminate_x, terminate_y;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
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
		cout << "#" << loop << " " << visited[terminate_y][terminate_x] << "\n";
	}
	return 0;
}