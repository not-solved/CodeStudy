#include <iostream>
using namespace std;

int chocolate[301][301];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int big = (n > m ? n : m);
    int small = m + n - big;
    for (int i = 1; i <= small; i++) {
        chocolate[i][i] = i * i - 1;
        for (int j = i + 1; j <= big; j++) {
            chocolate[i][j] = chocolate[i][j - 1] + i;
        }
    }
    cout << chocolate[small][big];
    return 0;
}