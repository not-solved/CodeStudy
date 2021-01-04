#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int x = (c * e - b * f) / (a * e - d * b);
    int y = (c * d - a * f) / (b * d - a * e);
    cout << x << ' ' << y;
    return 0;
}