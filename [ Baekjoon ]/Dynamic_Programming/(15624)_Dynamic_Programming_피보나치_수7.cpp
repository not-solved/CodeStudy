#include <iostream>
#include <queue>
using namespace std;

long long fibonacci[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    fibonacci[2] = 1;
    int input;
    cin >> input;
    for (int i = 2; i <= input; i++)
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 1000000007;
    cout << fibonacci[input];
    return 0;
}