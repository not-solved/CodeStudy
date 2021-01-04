#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long pibonacci[70];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int loop, command;
    cin >> loop;
    pibonacci[0] = 1;
    pibonacci[1] = 1;
    pibonacci[2] = 2;
    pibonacci[3] = 4;
    for (int i = 4; i <= 67; i++)
        pibonacci[i] = pibonacci[i - 1] + pibonacci[i - 2] + pibonacci[i - 3] + pibonacci[i - 4];
    while (loop--) {
        cin >> command;
        cout << pibonacci[command] << '\n';
    }
    return 0;
}