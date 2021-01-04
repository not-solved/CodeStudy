#include <iostream>
#include <queue>
using namespace std;

void hanoi(int n, int from, int by, int to, queue<pair<int, int>>& q) {
	if (n == 1)
		q.push(make_pair(from, to));
	else {
		hanoi(n - 1, from, to, by, q);
		q.push(make_pair(from, to));
		hanoi(n - 1, by, from, to, q);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	queue<pair<int, int>> Q;
	hanoi(n, 1, 2, 3, Q);
	cout << Q.size() << "\n";
	while (!Q.empty()) {
		cout << Q.front().first << " " << Q.front().second << "\n";
		Q.pop();
	}

	return 0;
}