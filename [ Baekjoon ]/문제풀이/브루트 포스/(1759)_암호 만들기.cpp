#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int L, int C, int idx, int c1, int c2, vector<char> chars, string temp) {
    if (temp.length() == L && c1 > 1 && c2 > 0) {
        cout << temp << '\n';
        return;
    }
    for (int i = idx; i < C; i++) {
        temp += chars[i];
        if (chars[i] == 'a' || chars[i] == 'e' || chars[i] == 'i' || chars[i] == 'o' || chars[i] == 'u')
            solve(L, C, i + 1, c1, c2 + 1, chars, temp);
        else
            solve(L, C, i + 1, c1 + 1, c2, chars, temp);
        temp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    int L, C;
    cin >> L >> C;
    vector<char> chars;
    char input;
    for (int i = 0; i < C; i++) {
        cin >> input;
        chars.push_back(input);
    }

    sort(chars.begin(), chars.end());

    solve(L, C, 0, 0, 0, chars, "");

    return 0;
}
