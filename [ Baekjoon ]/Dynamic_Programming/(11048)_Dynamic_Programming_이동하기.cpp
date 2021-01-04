#include <iostream>
#include <vector>
using namespace std;

int map[1001][1001];
int get_max(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    if (b >= a && b >= c)
        return b;
    if (c >= a && c >= b)
        return c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

    for (int i = 2; i <= m; i++)
        map[1][i] += map[1][i - 1];
    for (int i = 2; i <= n; i++)
        map[i][1] += map[i - 1][1];

    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            map[i][j] += get_max(map[i - 1][j - 1], map[i - 1][j], map[i][j - 1]);

    cout << map[n][m];
    return 0;
}