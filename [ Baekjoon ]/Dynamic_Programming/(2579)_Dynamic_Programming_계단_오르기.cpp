#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int stair[301] = { 0, };
int result[301] = { 0, };

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int stairs;
    cin >> stairs;
    for (int i = 1; i <= stairs; i++)
        cin >> stair[i];

    result[1] = stair[1];
    result[2] = stair[1] + stair[2];

    for (int i = 3; i <= stairs; i++)
        result[i] = max(result[i - 3] + stair[i - 1] + stair[i], result[i - 2] + stair[i]);

    cout << result[stairs];
    return 0;
}