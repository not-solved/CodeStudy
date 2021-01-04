#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[100];
bool visited[100];

void DFS(int a) {
	visited[a] = true;
	for (int i = 0; i < graph[a].size(); i++)
		if (!visited[graph[a][i]])
			DFS(graph[a][i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop = 10;
	for (int a = 1; a <= loop; a++) {
		int test, lines;
		cin >> test >> lines;

		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 100; i++)
			graph[i].clear();

		int from, to;
		for (int i = 0; i < lines; i++) {
			cin >> from >> to;
			graph[from].push_back(to);
		}
		DFS(0);

		cout << "#" << a << " " << visited[99] << "\n";
	}
	return 0;
}