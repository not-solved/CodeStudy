#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int n, k, input;
		cin >> n >> k;
		priority_queue<int> Q;
		for (int i = 0; i < n; i++) {
			cin >> input;
			Q.push(input);
		}
		int answer = 0;
		for (int i = 0; i < k; i++) {
			answer += Q.top();
			Q.pop();
		}
		cout << '#' << a << ' ' << answer << '\n';
	}
	return 0;
}