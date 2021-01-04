#include <iostream>
using namespace std;

int n;
bool map[15][15];

bool check(int row, int col) {
	// r위의 세로  ( | )
	for (int i = 0; i < row; i++)
		if (map[i][col])
			return false;

	int i = row - 1;
	int j = col - 1;
	while (i >= 0 && j >= 0) {
		if (map[i][j])
			return false;
		i -= 1;
		j -= 1;
	}

	i = row - 1;
	j = col + 1;
	while (i >= 0 && j < n) {
		if (map[i][j])
			return false;
		i -= 1;
		j += 1;
	}
	return true;
}
int NQ(int row) {
	if (row == n)
		return 1;
	int count = 0;

	for (int col = 0; col < n; col++) {
		if (check(row, col)) {
			map[row][col] = true;
			count += NQ(row + 1);
			map[row][col] = false;
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		cin >> n;
		cout << '#' << a << ' ' << NQ(0) << '\n';
	}
	return 0;
}