#include <iostream>
using namespace std;

long long A[46] = { 1, 0, 1, };
long long B[46] = { 0, 1, 1, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 3; i < 46; i++) {
        A[i] = A[i - 1] + A[i - 2];
        B[i] = B[i - 1] + B[i - 2];
    }
    int n;
    cin >> n;
    cout << A[n] << ' ' << B[n];
    return 0;
}