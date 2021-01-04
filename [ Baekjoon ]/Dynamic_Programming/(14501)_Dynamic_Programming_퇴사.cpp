#include <iostream>
#include <vector>
#include <string>
using namespace std;

int day[17];
int pay[17];
int dp[17] = { 0, };


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, answer = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> day[i] >> pay[i];

    for (int i = 1; i <= n; i++) {
        // 상담을 진행하고 급료를 받을 경우 급료를 더함
        if (i + day[i] <= n + 1) {
            dp[i + day[i]] = (dp[i + day[i]] > dp[i] + pay[i] ? dp[i + day[i]] : dp[i] + pay[i]);
            answer = (answer > dp[i + day[i]] ? answer : dp[i + day[i]]);
        }
        // 상담을 진행하지 않을 경우 급료를 더하지 않고 갱신
        dp[i + 1] = (dp[i + 1] > dp[i] ? dp[i + 1] : dp[i]);
        answer = (answer > dp[i + 1] ? answer : dp[i + 1]);
    }
    cout << answer;
    return 0;
}
