#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size;
    cin >> size;
    vector<int> price(size), distance(size);
    for (int i = 0; i < size; i++)
        cin >> distance[i] >> price[i];
    int candidates = 0;
    for (int i = 0; i < size; i++) {
        bool OK = true;
        for (int j = 0; j < size; j++) {
            if (i == j)
                continue;
            // 콘도 X보다 더 가까운 경우
            if (distance[i] >= distance[j]) {
                if (price[i] >= price[j]) {
                    OK = false;
                    break;
                }
            }
            if (price[i] >= price[j]) {
                if (distance[i] >= distance[j]) {
                    OK = false;
                    break;
                }
            }
        }
        if (OK)
            candidates++;
    }
    cout << candidates;
    return 0;
}
