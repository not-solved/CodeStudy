#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int map[51][51];
    int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    queue<pair<int, int>> Q;

    int y, x;
    do {
        cin >> x >> y;
        if (y == 0 && x == 0)
            break;
        for (int i = 1; i <= y; i++)
            for (int j = 1; j <= x; j++)
                cin >> map[i][j];

        int y_t, x_t, Land = 0;
        for (int i = 1; i <= y; i++) {
            for (int j = 1; j <= x; j++) {

                if (map[i][j] == 1) {
                    Q.push(make_pair(i, j));
                    map[i][j] = 0;
                    Land++;
                    while (!Q.empty()) {
                        y_t = Q.front().first;
                        x_t = Q.front().second;
                        Q.pop();
                        for (int a = 0; a < 8; a++) {
                            if (map[y_t + dy[a]][x_t + dx[a]] == 1) {
                                map[y_t + dy[a]][x_t + dx[a]] = 0;
                                Q.push(make_pair(y_t + dy[a], x_t + dx[a]));
                            }
                        }
                    }
                }
            }
        }
        cout << Land << '\n';
    } while (true);
    return 0;
}
