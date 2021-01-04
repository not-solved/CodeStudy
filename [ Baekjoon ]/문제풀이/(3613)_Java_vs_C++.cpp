#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    cin >> input;

    bool C = false, Java = false, Err = false;
    string output = "";
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            if (i == 0 || C) {
                Err = true;
                break;
            }
            output += '_';
            output += (input[i] + 32);
            Java = true;
        }
        else if (input[i] == '_') {
            if (i == 0 || Java || i + 1 == input.length() || input[i + 1] == '_' || (input[i + 1] >= 'A' && input[i + 1] <= 'Z')) {
                Err = true;
                break;
            }
            output += (input[i + 1] - 32);
            i++;
            C = true;
        }
        else
            output += input[i];
    }
    if (Err)
        cout << "Error!\n";
    else
        cout << output << "\n";
    return 0;
}