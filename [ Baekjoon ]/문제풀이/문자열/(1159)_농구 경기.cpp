#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int chars[27] = { 0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int loop;
    cin >> loop;
    vector<char> slot;
    string input;
    while (loop--) {
        cin >> input;
        chars[input[0] - 97]++;
        if (chars[input[0] - 97] == 5)
            slot.push_back(input[0]);
    }
    if (slot.empty())
        cout << "PREDAJA";
    else {
        sort(slot.begin(), slot.end());
        for (int i = 0; i < slot.size(); i++) {
            cout << slot[i];
        }
    }
    return 0;
}

