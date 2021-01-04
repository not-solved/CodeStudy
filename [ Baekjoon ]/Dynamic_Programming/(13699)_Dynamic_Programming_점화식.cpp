#include <iostream>
using namespace std;

long long dp[36] = { 0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            dp[i] += (dp[j] * dp[i - j - 1]);
        }
    }
    cout << dp[n];
    return 0;
}