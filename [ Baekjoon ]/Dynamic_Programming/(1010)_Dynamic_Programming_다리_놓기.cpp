#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a[4] = { 0, 1, 2, 3 };
int dp[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < 4; i++)
        dp[i] = a[i];
    for (int i = 4; i * i <= n; i++) {
        dp[i] = 1;
        int idx = 0;
        for (int j = i + 1; j < (i + 1) * (i + 1) && j <= n; j++) {
            dp[j] = dp[i] + (idx / 4) + a[idx % 4];
        }
    }
    cout << dp[n];
    return 0;
}
