#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ver, hor, loop, com, len;
    cin >> ver >> hor;
    cin >> loop;

    vector<int> V, H;
    V.push_back(0);
    V.push_back(ver);
    H.push_back(0);
    H.push_back(hor);
    while (loop--) {
        cin >> com >> len;
        if (com == 0)
            H.push_back(len);
        else
            V.push_back(len);
    }
    sort(V.begin(), V.end());
    sort(H.begin(), H.end());
    int size = -1;
    for (int i = 1; i < V.size(); i++) {
        for (int j = 1; j < H.size(); j++) {
            if (size < (V[i] - V[i - 1]) * (H[j] - H[j - 1]))
                size = (V[i] - V[i - 1]) * (H[j] - H[j - 1]);
        }
    }
    cout << size;

    return 0;
}