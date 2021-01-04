#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cards[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cards[i];

    // 0장 구매시 가격은 0
    cards[0] = 0;
    dp[0] = 0;

    // n장을 구매할 경우, 1 ~ n-1장 카드팩의 조합을 모두 고려
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = (dp[i] > dp[i - j] + cards[j] ? dp[i] : dp[i - j] + cards[j]);
        }
    }
    cout << dp[n];
    return 0;
}
