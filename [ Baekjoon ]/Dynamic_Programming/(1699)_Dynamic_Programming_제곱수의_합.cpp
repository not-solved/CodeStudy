#include <iostream>
using namespace std;

int dp[100001];

int Min(int a, int b) {
    return (a > b ? b : a);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        dp[i] = i;

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j * j <= i; j++) {
            dp[i] = Min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
    return 0;
}
