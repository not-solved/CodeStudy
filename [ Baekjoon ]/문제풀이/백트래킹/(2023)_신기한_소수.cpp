#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool check_prime(int target) {
    if (target < 2)
        return false;
    for (int i = 2; i * i <= target; i++) {
        if (target % i == 0)
            return false;
    }
    return true;
}

void calculate(int temp, int size) {
    if (size == 0) {
        cout << temp << '\n';
        return;
    }
    for (int i = 1; i < 10; i += 2) {
        if (check_prime(temp * 10 + i)) {
            calculate(temp * 10 + i, size - 1);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int prime[4] = { 2, 3, 5, 7 };
    for (int i = 0; i < 4; i++) {
        calculate(prime[i], N - 1);
    }
    return 0;
}