#include <iostream>
#include <vector>
#include <string>
using namespace std;

string N = "0123456789";
string calculate(string exp) {
    int op = 0, idx = 0;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '+') {
            op += stoi(exp.substr(idx, i - idx));
            idx = i + 1;
            continue;
        }
        if (i == exp.length() - 1) {
            op += stoi(exp.substr(idx, i - idx + 1));
        }
    }
    return to_string(op);
}
int split_and_calculate(string exp) {
    vector<string> result;
    int idx = 0;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '-') {
            result.push_back(exp.substr(idx, i - idx));
            idx = i + 1;
        }
    }
    result.push_back(exp.substr(idx, exp.length() - idx));
    int output = 0;
    for (int i = 0; i < result.size(); i++) {
        if (i == 0)
            output += stoi(calculate(result[i]));
        else
            output -= stoi(calculate(result[i]));
    }
    return output;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string exp;
    cin >> exp;
    cout << split_and_calculate(exp);
    return 0;
}
