#include <iostream>
using namespace std;

int fly[15][15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> fly[i][j];

		int sum = 0;
		int max = 0;
		for (int i = 0; i <= n - m; i++) {
			for (int j = 0; j <= n - m; j++) {
				sum = 0;
				for (int y = i; y < i + m; y++)
					for (int x = j; x < j + m; x++)
						sum += fly[y][x];
				if (sum > max)
					max = sum;
			}
		}
		cout << "#" << a << " " << max << "\n";
	}
	return 0;
}