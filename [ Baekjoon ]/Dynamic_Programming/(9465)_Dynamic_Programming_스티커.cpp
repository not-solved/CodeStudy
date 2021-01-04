#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dp[2][100001];

int max(int a, int b) {
    return (a > b ? a : b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int loop;
    cin >> loop;
    while (loop--) {
        int n;
        cin >> n;
        for (int a = 0; a < 2; a++)
            for (int i = 1; i <= n; i++)
                cin >> dp[a][i];

        for (int i = 2; i <= n; i++) {
            dp[0][i] += max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] += max(dp[0][i - 1], dp[0][i - 2]);
        }
        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
    return 0;
}