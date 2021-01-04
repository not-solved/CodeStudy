#include <iostream>
using namespace std;

int dp[501][501];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];
			if (dp[i - 1][j - 1] >= dp[i - 1][j])
				dp[i][j] += dp[i - 1][j - 1];
			else
				dp[i][j] += dp[i - 1][j];
		}
	}
	int max = dp[n][1];
	for (int i = 2; i <= n; i++) {
		if (max < dp[n][i])
			max = dp[n][i];
	}
	cout << max;

	return 0;
}