#include <iostream>
#include <algorithm>
using namespace std;

int snacks[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int test = 1; test <= loop; test++) {
		int n, m;
		cin >> n >> m;
		int sum = 0;
		for (int i = 0; i < n; i++)
			cin >> snacks[i];
		sort(&snacks[0], &snacks[n - 1]);
		int index = n - 1;
		for (; index >= 0; index--) {
			if (snacks[index] < m)
				break;
		}
		int max = -1;
		for (int i = 0; i <= index - 1; i++) {
			for (int j = i + 1; j <= index; j++) {
				sum = snacks[i] + snacks[j];
				if (sum <= m)
					if (sum > max)
						max = sum;
			}
		}
		cout << "#" << test << " " << max << "\n";
	}
	return 0;
}