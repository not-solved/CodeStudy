#include <iostream>
using namespace std;

int map[51][51];
bool visited[51][51];

void DFS(int y, int x) {
	visited[y][x] = true;
	if (map[y + 1][x] == 1 && visited[y + 1][x] == false)
		DFS(y + 1, x);
	if (map[y - 1][x] == 1 && visited[y - 1][x] == false)
		DFS(y - 1, x);
	if (map[y][x + 1] == 1 && visited[y][x + 1] == false)
		DFS(y, x + 1);
	if (map[y][x - 1] == 1 && visited[y][x - 1] == false)
		DFS(y, x - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test;
	cin >> test;
	int m, n, cabbage, a, b, count;
	while (test--) {
		count = 0;
		cin >> m >> n >> cabbage;
		for (int i = 0; i < cabbage; i++) {
			cin >> a >> b;
			map[b][a] = 1;
		}
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (map[y][x] == 1 && visited[y][x] == false) {
					count++;
					DFS(y, x);
				}
			}
		}
		cout << count << '\n';
		fill(&visited[0][0], &visited[n - 1][m], false);
		fill(&map[0][0], &map[n - 1][m], 0);
	}
	return 0;
}