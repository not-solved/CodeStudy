#include <iostream>
#include <string>
using namespace std;

string Decimal[10] = { "000", "001", "010", "011", "100", "101", "110", "111", "", "" };
string Firstdec[10] = { "0", "1", "10", "11", "100", "101", "110", "111", "","" };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string oct;
    cin >> oct;
    for (int i = 0; i < oct.length(); i++) {
        if (!i) {
            cout << Firstdec[oct[i] - 48];
        }
        else {
            cout << Decimal[oct[i] - 48];
        }
    }
    return 0;
}