#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string result = "";

void reconstruct(string input, int first, int second) {

    vector<string> slot(3, "");

    for (int i = 0; i <= first; i++)
        slot[0] = slot[0] + input[i];
    for (int i = first + 1; i <= second; i++)
        slot[1] = slot[1] + input[i];
    for (int i = second + 1; i < input.length(); i++)
        slot[2] = slot[2] + input[i];
    // slot[0] = input.substr(0, first);
    // slot[1] = input.substr(first, second - first);
    // slot[2] = input.substr(second, input.length() - second);

    for (int i = 0; i < 3; i++)
        reverse(slot[i].begin(), slot[i].end());

    string temp = slot[0] + slot[1] + slot[2];
    if (result == "" || result > temp)
        result = temp;
}

void calculate(string input) {
    for (int i = 0; i < input.length() - 1; i++)
        for (int j = i + 1; j < input.length() - 1; j++)
            reconstruct(input, i, j);

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    cin >> input;
    calculate(input);

    return 0;
}