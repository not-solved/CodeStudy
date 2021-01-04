#include <iostream>
#include <vector>
using namespace std;

int find_number(int n, int k) {
    vector<int> P(1001, 0);
    bool finish = false;

    while (!finish) {
        for (int i = 2; i <= n; i++) {
            if (P[i] == 0) {
                P[i] = 1;
                if ((--k) <= 0)
                    return i;
                for (int j = 2; j * i <= n; j++) {
                    if (P[i * j] == 0) {
                        P[i * j] = 1;
                        if ((--k) <= 0)
                            return i * j;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    cout << find_number(N, K);
    return 0;
}