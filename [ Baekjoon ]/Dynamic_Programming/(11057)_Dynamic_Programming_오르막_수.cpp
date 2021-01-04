#include <iostream>
using namespace std;

int num[11][1001] = { 0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    /*
    n   1   2   3

    0   1   10  1~10
    1   1   9   1~9
    2   1   8   1~8
    3   1   7   1~7
    4   1   6   1~6
    5   1   5   1~5
    6   1   4   1~4
    7   1   3   1~3
    8   1   2   1~2
    9   1   1   1

    */
    for (int i = 0; i < 10; i++)
        num[i][1] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 10; k >= j; k--)
                num[j][i] = (num[k][i - 1] + num[j][i]) % 10007;
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum = (sum + num[i][n]) % 10007;
    cout << sum;
    return 0;
}