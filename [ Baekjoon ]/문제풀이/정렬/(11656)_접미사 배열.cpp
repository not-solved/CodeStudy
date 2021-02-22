#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    cin >> input;
    vector<string> result;
    int idx = 0;
    while (idx < input.length()) {
        result.push_back(input.substr(idx, input.length() - idx));
        idx++;
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';

    return 0;
}