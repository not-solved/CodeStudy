#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, min, max = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        min = 0;
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j])
                if (min < dp[j])
                    min = dp[j];
        }
        dp[i] = min + 1;
        if (max < dp[i])
            max = dp[i];
    }
    cout << max;

    return 0;
}
