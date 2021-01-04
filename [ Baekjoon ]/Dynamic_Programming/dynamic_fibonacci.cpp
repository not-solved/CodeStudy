#include <iostream>
using namespace std;

long long dp[100];

long long fibonacci(long long x) {
	if (x == 1 || x == 2)
		return 1;
	if (dp[x] != 0)
		return dp[x];
	return dp[x] = fibonacci(x - 1) + fibonacci(x - 2);
}

int main() {
	long long N;
	cin >> N;
	cout << fibonacci(N) << endl;
	return 0;
}