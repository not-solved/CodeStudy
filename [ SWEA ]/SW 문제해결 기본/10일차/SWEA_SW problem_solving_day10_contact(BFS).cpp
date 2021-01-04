#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> map[101];
bool visited[101];
int biggest = 0;

void BFS(int start) {
	memset(visited, false, sizeof(visited));
	biggest = 0;
	visited[start] = true;
	int length = 1;
	queue<int> time;
	queue<int> call;
	call.push(start);
	time.push(length);
	while (!call.empty()) {
		int temp = call.front();
		call.pop();
		if (time.front() > length)
			biggest = 0;
		length = time.front();
		time.pop();
		if (biggest < temp)
			biggest = temp;
		for (int i = 0; i < map[temp].size(); i++) {
			if (!visited[map[temp][i]]) {
				call.push(map[temp][i]);
				time.push(length + 1);
				visited[map[temp][i]] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int a = 1; a <= 10; a++) {
		int lines, start;
		cin >> lines >> start;

		int from, to;
		for (int i = 0; i <= 100; i++)
			map[i].clear();
		for (int i = 0; i < lines / 2; i++) {
			cin >> from >> to;
			map[from].push_back(to);
		}

		BFS(start);
		cout << "#" << a << " " << biggest << "\n";
	}
	return 0;
}