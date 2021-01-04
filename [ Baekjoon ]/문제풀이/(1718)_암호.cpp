#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input, key;
    getline(cin, input);
    cin >> key;
    string output = input;
    for (int i = 0; i < input.length(); i++) {
        if (output[i] == ' ')
            continue;

        output[i] -= (key[i % key.length()] - 96);
        if (output[i] < 'a') {
            output[i] = 'z' - (96 - output[i]);
        }
    }
    cout << output;
    return 0;
}