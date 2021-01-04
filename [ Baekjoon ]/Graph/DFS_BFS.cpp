#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

queue<int> Q;
vector<int> graph[1001];
bool visited[1001];

void DFS(int a) {
	visited[a] = true;
	cout << a << " ";
	for (int i = 0; i < graph[a].size(); i++)
		if (!visited[graph[a][i]])
			DFS(graph[a][i]);
}

void BFS(int a) {
	Q.push(a);
	visited[a] = true;
	while (!Q.empty()) {
		int temp = Q.front();
		Q.pop();
		cout << temp << " ";
		for (int i = 0; i < graph[temp].size(); i++) {
			if (!visited[graph[temp][i]]) {
				Q.push(graph[temp][i]);
				visited[graph[temp][i]] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, start;
	cin >> n >> m >> start;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	DFS(start);
	cout << "\n";
	memset(visited, false, 1001);
	BFS(start);

	return 0;
}