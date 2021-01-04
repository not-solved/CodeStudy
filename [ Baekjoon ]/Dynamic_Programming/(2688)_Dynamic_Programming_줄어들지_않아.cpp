#include <iostream>
#include <queue>
using namespace std;

long long dp[10][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= 1000; i++) {
        for (int j = 0; j < 10; j++) {
            long long temp = 0;
            for (int k = j; k < 10; k++)
                temp += dp[k][i - 1];
            dp[j][i] = temp;
        }
    }

    int loop, input;
    cin >> loop;
    while (loop--) {
        cin >> input;
        cout << dp[0][input] << endl;
    }
    return 0;
}