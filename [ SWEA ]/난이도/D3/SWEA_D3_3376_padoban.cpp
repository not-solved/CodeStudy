#include <iostream>
using namespace std;

long long dp[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i <= 100; i++)
		dp[i] = dp[i - 5] + dp[i - 1];

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int n;
		cin >> n;
		cout << '#' << a << ' ' << dp[n] << '\n';
	}

	return 0;
}