#include <iostream>
#include <string>
using namespace std;

string compare(string a, string b) {
    if (a.length() != b.length())
        return "DIFF";
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == 'B') {
            if (b[i] == 'B')
                continue;
            else
                return "DIFF";
        }
        else if (a[i] == 'A' || a[i] == 'D' ||
            (a[i] >= 'O' && a[i] <= 'R')) {
            if (b[i] == 'A' || b[i] == 'D' ||
                (b[i] >= 'O' && b[i] <= 'R'))
                continue;
            else {
                return "DIFF";
            }
        }
        else {
            if (b[i] == 'A' || b[i] == 'B' || b[i] == 'D' ||
                (b[i] >= 'O' && b[i] <= 'R'))
                return "DIFF";
        }
    }
    return "SAME";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int loop;
    cin >> loop;
    for (int A = 1; A <= loop; A++) {
        string in1, in2;
        cin >> in1 >> in2;
        cout << '#' << A << ' ' << compare(in1, in2) << '\n';
    }
    return 0;
}