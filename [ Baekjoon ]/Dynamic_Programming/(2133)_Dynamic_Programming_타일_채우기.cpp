#include <iostream>
using namespace std;

int dp[31] = { 0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int length;
    cin >> length;
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= length; i += 2) {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2)
            dp[i] += dp[i - j] * 2;
    }
    cout << dp[length];
    return 0;
}