#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long map[201][201];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++)
        map[1][i] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= j; l++) {
                map[i][j] += map[i - 1][j - l];
                map[i][j] %= 1000000000;
            }
        }
    }
    cout << map[k][n];

    return 0;
}