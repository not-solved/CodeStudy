#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char farm[51][51];
bool visited[51][51];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int gain = 0;

void BFS(int tries, int y, int x) {
	int count;
	queue<pair<int, int>> Q;
	queue<int> C;
	Q.push(make_pair(y, x));
	C.push(1);
	visited[y][x] = true;
	gain += farm[y][x] - 48;
	while (!Q.empty() && C.front() <= tries) {
		int ny = Q.front().first;
		int nx = Q.front().second;
		count = C.front();
		Q.pop();
		C.pop();
		for (int i = 0; i < 4; i++) {
			if (ny + dy[i] > -1 && ny + dy[i] < 50 && nx + dx[i] > -1 && nx + dx[i] < 50) {
				if (!visited[ny + dy[i]][nx + dx[i]]) {
					gain += farm[ny + dy[i]][nx + dx[i]] - 48;
					Q.push(make_pair(ny + dy[i], nx + dx[i]));
					C.push(count + 1);
					visited[ny + dy[i]][nx + dx[i]] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int S;
		cin >> S;
		gain = 0;
		for (int i = 0; i < S; i++)
			for (int j = 0; j < S; j++)
				cin >> farm[i][j];
		memset(visited, false, sizeof(visited));
		int tries = S / 2;
		BFS(tries, tries, tries);

		cout << '#' << a << ' ' << gain << '\n';
	}
	return 0;
}