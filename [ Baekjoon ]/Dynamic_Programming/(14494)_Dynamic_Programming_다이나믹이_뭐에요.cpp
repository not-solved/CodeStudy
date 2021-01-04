#include <iostream>
using namespace std;

int map[1001][1001] = { 0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
        map[1][i] = 1;
    for (int i = 1; i <= n; i++)
        map[i][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            map[i][j] = map[i - 1][j - 1];
            map[i][j] = (map[i][j] + map[i - 1][j]) % 1000000007;
            map[i][j] = (map[i][j] + map[i][j - 1]) % 1000000007;
        }
    }

    cout << map[n][m];
    return 0;
}