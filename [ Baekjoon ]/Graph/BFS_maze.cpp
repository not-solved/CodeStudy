#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int, int>> Q;
queue<int> dist;
bool visited[101][101];
char map[101][101];

int BFS(int y_dest, int x_dest, int count) {
	Q.push(make_pair(1, 1));
	dist.push(count);
	visited[1][1] = true;
	int result = count;
	int y_temp = 0;
	int x_temp = 0;
	while (true) {
		y_temp = Q.front().first;
		x_temp = Q.front().second;
		result = dist.front();
		if (y_temp == y_dest && x_temp == x_dest)
			break;
		Q.pop();
		dist.pop();
		if (map[y_temp + 1][x_temp] == '1' && visited[y_temp + 1][x_temp] == false) {
			Q.push(make_pair(y_temp + 1, x_temp));
			dist.push(result + 1);
			visited[y_temp + 1][x_temp] = true;
		}
		if (map[y_temp][x_temp + 1] == '1' && visited[y_temp][x_temp + 1] == false) {
			Q.push(make_pair(y_temp, x_temp + 1));
			dist.push(result + 1);
			visited[y_temp][x_temp + 1] = true;
		}
		if (map[y_temp - 1][x_temp] == '1' && visited[y_temp - 1][x_temp] == false) {
			Q.push(make_pair(y_temp - 1, x_temp));
			dist.push(result + 1);
			visited[y_temp - 1][x_temp] = true;
		}
		if (map[y_temp][x_temp - 1] == '1' && visited[y_temp][x_temp - 1] == false) {
			Q.push(make_pair(y_temp, x_temp - 1));
			dist.push(result + 1);
			visited[y_temp][x_temp - 1] = true;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> y >> x;
	for (int i = 1; i <= y; i++)
		for (int j = 1; j <= x; j++)
			cin >> map[i][j];

	memset(visited, false, 10201);

	cout << BFS(y, x, 1);
	return 0;
}