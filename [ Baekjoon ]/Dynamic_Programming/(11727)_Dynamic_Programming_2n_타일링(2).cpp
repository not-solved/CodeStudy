#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long tile[1001] = { 0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int length;
    cin >> length;

    tile[1] = 1;
    tile[2] = 3;

    for (int i = 3; i <= length; i++)
        tile[i] = (tile[i - 1] + tile[i - 2] * 2) % 10007;

    cout << tile[length];
    return 0;
}
