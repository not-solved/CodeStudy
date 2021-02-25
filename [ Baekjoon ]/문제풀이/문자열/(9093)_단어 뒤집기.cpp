#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cnt;
    string input;

    cin >> cnt;
    getline(cin, input);
    while (cnt--) {
        getline(cin, input);

        int idx_f = 0, idx_b = 0, idx = 0;
        while (idx < input.length()) {
            if (input[idx] == ' ' || idx == input.length() - 1) {
                idx_b = (idx < input.length() - 1 ? idx - 1 : idx);
                char temp;
                while (idx_f < idx_b) {
                    temp = input[idx_f];
                    input[idx_f] = input[idx_b];
                    input[idx_b] = temp;
                    idx_f++;
                    idx_b--;
                }
                idx_f = idx + 1;
                idx_b = idx + 1;
            }
            idx++;
        }
        cout << input << '\n';
    }
    return 0;
}