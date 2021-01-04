#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int n, input;
		cin >> n;
		stack<int> S;
		for (int i = 0; i < n; i++) {
			cin >> input;
			if (input == 0) {
				if (!S.empty())
					S.pop();
			}
			else {
				S.push(input);
			}
		}
		int sum = 0;
		while (!S.empty()) {
			sum += S.top();
			S.pop();
		}
		cout << "#" << a << " " << sum << "\n";
	}
	return 0;
}