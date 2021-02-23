#include <iostream>
#include <queue>
using namespace std;

char map[101][101];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };


int getGroup(int size) {
    int cnt = 0;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (map[i][j] == 'R' || map[i][j] == 'G' || map[i][j] == 'B') {
                queue<pair<int, int>> Q;
                char base = map[i][j];
                if (base == 'B')
                    map[i][j] = 'b';
                else
                    map[i][j] = 'r';
                int tx, ty;
                Q.push({ i, j });
                cnt++;
                while (!Q.empty()) {
                    ty = Q.front().first;
                    tx = Q.front().second;
                    Q.pop();
                    for (int a = 0; a < 4; a++) {
                        if (map[ty + dy[a]][tx + dx[a]] == base) {
                            Q.push({ ty + dy[a], tx + dx[a] });
                            if (base == 'B')
                                map[ty + dy[a]][tx + dx[a]] = 'b';
                            else
                                map[ty + dy[a]][tx + dx[a]] = 'r';
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int getBlind(int size) {
    int cnt = 0;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (map[i][j] == 'r' || map[i][j] == 'b') {
                queue<pair<int, int>> Q;
                char base = map[i][j];
                map[i][j] = 'z';
                int tx, ty;
                Q.push({ i, j });
                cnt++;
                while (!Q.empty()) {
                    ty = Q.front().first;
                    tx = Q.front().second;
                    Q.pop();
                    for (int a = 0; a < 4; a++) {
                        if (map[ty + dy[a]][tx + dx[a]] == base) {
                            Q.push({ ty + dy[a], tx + dx[a] });
                            map[ty + dy[a]][tx + dx[a]] = 'z';
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size;
    cin >> size;
    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++)
            cin >> map[i][j];

    int result1 = getGroup(size);
    int result2 = getBlind(size);

    cout << result1 << ' ' << result2;
    return 0;
}
