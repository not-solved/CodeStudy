#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    int small, big, num, space;
    while (getline(cin, input)) {
        small = 0;
        big = 0;
        num = 0;
        space = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] >= 'a' && input[i] <= 'z')
                small++;
            else if (input[i] >= 'A' && input[i] <= 'Z')
                big++;
            else if (input[i] >= '0' && input[i] <= '9')
                num++;
            else if (input[i] == ' ')
                space++;
        }
        cout << small << ' ' << big << ' ' << num << ' ' << space << '\n';
        input.clear();
    }
    return 0;
}