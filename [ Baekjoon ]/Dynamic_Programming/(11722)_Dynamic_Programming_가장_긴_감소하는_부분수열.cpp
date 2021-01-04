#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, answer = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        int max = 0;
        for (int j = 1; j < i; j++) {
            if (arr[i] < arr[j])
                if (max < dp[j])
                    max++;
        }
        dp[i] = max + 1;
        if (answer < dp[i])
            answer = dp[i];
    }
    cout << answer;
    return 0;
}
