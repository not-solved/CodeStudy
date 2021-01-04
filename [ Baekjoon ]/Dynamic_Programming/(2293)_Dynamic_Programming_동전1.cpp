#include <iostream>
#include <vector>
using namespace std;

int coin[101];
int dp[10001] = { 0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            if (j >= coin[i])
                dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[k];
    return 0;
}