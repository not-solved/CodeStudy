#include <iostream>
#include <queue>
using namespace std;

long long call[51] = { 0, };


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    call[0] = 1;
    call[1] = 1;
    for (int i = 2; i <= 50; i++)
        call[i] = (call[i - 1] + call[i - 2] + 1) % 1000000007;

    int input;
    cin >> input;
    cout << call[input];
    return 0;
}