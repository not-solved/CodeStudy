#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[501][501];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

    queue<pair<int, int>> coord;
    int max_size = 0, pictures = 0, size = 0, tx, ty;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j]) {
                map[i][j] = 0;
                pictures++;
                size = 1;
                coord.push({ i, j });
                while (!coord.empty()) {
                    ty = coord.front().first;
                    tx = coord.front().second;
                    coord.pop();
                    for (int a = 0; a < 4; a++) {
                        if (ty + dy[a] < 1 || ty + dy[a] > n || tx + dx[a] < 1 || tx + dx[a] > m)
                            continue;
                        if (map[ty + dy[a]][tx + dx[a]]) {
                            size++;
                            map[ty + dy[a]][tx + dx[a]] = 0;
                            coord.push({ ty + dy[a], tx + dx[a] });
                        }
                    }
                }
                if (size > max_size)
                    max_size = size;
            }
        }
    }
    cout << pictures << '\n' << max_size;
    return 0;
}