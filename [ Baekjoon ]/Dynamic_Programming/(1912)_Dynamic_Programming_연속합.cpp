#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long dp[100000];
long long in[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int loop, answer;
    cin >> loop;

    for (int i = 0; i < loop; i++)
        cin >> in[i];

    dp[0] = in[0];
    answer = dp[0];
    for (int i = 1; i < loop; i++) {
        dp[i] = (in[i] < dp[i - 1] + in[i] ? dp[i - 1] + in[i] : in[i]);
        answer = (answer < dp[i] ? dp[i] : answer);
    }
    cout << answer;
    return 0;
}
