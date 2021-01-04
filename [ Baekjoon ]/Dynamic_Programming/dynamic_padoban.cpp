#include <iostream>
using namespace std;

long long dp[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int m;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i < 101; i++)
		dp[i] = dp[i - 5] + dp[i - 1];

	while (n--) {
		cin >> m;
		cout << dp[m] << "\n";
	}

	return 0;
}