#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool check_prime(long long target) {
    for (long long i = 2; i * i <= target; i++) {
        if (target % i == 0)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    for (long long i = 7; i <= min(k, 59); i++) {
        vector<long long> result;
        if (check_prime(i)) {
            long long mersenne = (1LL << i) - 1;
            for (long long j = 3; j * j <= mersenne; j += 2) {
                if (mersenne % j == 0) {
                    mersenne /= j;
                    result.push_back(j);
                }
            }
            result.push_back(mersenne);
        }
        if (result.size() > 1) {
            for (int j = 0; j < result.size(); j++) {
                if (j != 0)
                    cout << " * ";
                cout << result[j];
            }
            cout << " = " << (1LL << i) - 1 << " = ( 2 ^ " << i << " ) - 1\n";
        }
    }
    return 0;
}