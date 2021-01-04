#include <iostream>
#include <queue>
using namespace std;

long long Pascal[31][31];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int height, k;
    cin >> height >> k;
    for (int i = 1; i <= height; i++) {
        Pascal[i][1] = 1;
        for (int j = 2; j <= i; j++) {
            if (j == i)
                Pascal[i][j] = 1;
            else
                Pascal[i][j] = Pascal[i - 1][j - 1] + Pascal[i - 1][j];
        }
    }
    cout << Pascal[height][k];
    return 0;
}