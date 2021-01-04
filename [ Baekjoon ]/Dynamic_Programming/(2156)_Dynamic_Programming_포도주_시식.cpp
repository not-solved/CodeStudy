#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001] = { 0, };
int result[10001] = { 0, };

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int wines;
    cin >> wines;
    for (int i = 1; i <= wines; i++)
        cin >> wine[i];

    result[1] = wine[1];
    result[2] = wine[1] + wine[2];

    for (int i = 3; i <= wines; i++) {
        result[i] = max(wine[i] + result[i - 2], wine[i] + wine[i - 1] + result[i - 3]);
        result[i] = max(result[i], result[i - 1]);
    }

    cout << result[wines];
    return 0;
}