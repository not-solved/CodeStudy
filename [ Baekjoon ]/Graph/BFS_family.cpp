#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int visited[101];
vector<int> family[101];

int BFS(int index, int end) {
	visited[index] = 0;
	queue<int> list;
	list.push(index);
	while (!list.empty()) {
		int temp = list.front();
		list.pop();
		if (temp == end)
			return visited[end];
		for (int i = 0; i < family[temp].size(); i++) {
			if (visited[family[temp][i]] == -1) {
				list.push(family[temp][i]);
				visited[family[temp][i]] = visited[temp] + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(visited, -1, sizeof(visited));
	int people, start, end, links;
	cin >> people >> start >> end >> links;
	int a, b;
	while (links--) {
		cin >> a >> b;
		family[a].push_back(b);
		family[b].push_back(a);
	}

	cout << BFS(start, end) << "\n";
	return 0;
}