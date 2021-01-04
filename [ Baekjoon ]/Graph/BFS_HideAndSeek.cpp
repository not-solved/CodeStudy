#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX	100000
using namespace std;

queue<int> Q;
queue<int> dist;
bool visited[MAX + 1];
char map[MAX + 1];

int BFS(int from, int to, int count) {
	Q.push(from);
	dist.push(count);
	visited[from] = true;
	int result = count;
	int current = from;
	while (current != to) {
		current = Q.front();
		result = dist.front();
		Q.pop();
		dist.pop();
		if (current == to)
			break;
		if (current + 1 <= MAX) {
			if (visited[current + 1] == false) {
				Q.push(current + 1);
				dist.push(result + 1);
				visited[current + 1] = true;
			}
		}
		if (current - 1 >= 0) {
			if (visited[current - 1] == false) {
				Q.push(current - 1);
				dist.push(result + 1);
				visited[current - 1] = true;
			}
		}
		if (current * 2 <= MAX) {
			if (visited[current * 2] == false) {
				Q.push(current * 2);
				dist.push(result + 1);
				visited[current * 2] = true;
			}
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int from, to;
	cin >> from >> to;

	cout << BFS(from, to, 0);
	return 0;
}