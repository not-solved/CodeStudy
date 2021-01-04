#include <iostream>
#include <queue>
using namespace std;

long long dp[31][31] = { 0, };

long long pill(int w, int h) {
    if (dp[w][h])
        return dp[w][h];
    if (w == 0)
        return 1;

    dp[w][h] = pill(w - 1, h + 1);
    if (h > 0)
        dp[w][h] += pill(w, h - 1);
    return dp[w][h];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 30; i++)
        pill(i, 0);

    int input;
    do {
        cin >> input;
        if (input == 0)
            break;
        cout << dp[input][0] << '\n';

    } while (input > 0);
    return 0;
}