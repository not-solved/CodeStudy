#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int n, m, input;
		cin >> n >> m;
		int count = 0;
		int max = 0;
		int winner = 0;
		for (int i = 0; i < n; i++) {
			count = 0;
			for (int j = 0; j < m; j++) {
				cin >> input;
				if (input == 1)
					count++;
			}
			if (max == count)
				winner++;
			if (max < count) {
				max = count;
				winner = 1;
			}
		}

		cout << '#' << a << ' ' << winner << ' ' << max << '\n';
	}
	return 0;
}