#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool desc(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num, nation, number, score;
    cin >> num;
    vector<pair<int, pair<int, int>>> result;
    while (num--) {
        cin >> nation >> number >> score;
        result.push_back({ score, {nation, number} });
    }
    sort(result.begin(), result.end(), desc);

    cout << result[0].second.first << ' ' << result[0].second.second << '\n';
    if (result[1].second.first == result[0].second.first) {
        cout << result[1].second.first << ' ' << result[1].second.second << '\n';
        int idx = 2;
        while (result[idx].second.first == result[1].second.first) {
            idx++;
        }
        cout << result[idx].second.first << ' ' << result[idx].second.second << '\n';
    }
    else {
        cout << result[1].second.first << ' ' << result[1].second.second << '\n';
        cout << result[2].second.first << ' ' << result[2].second.second << '\n';
    }

    return 0;
}