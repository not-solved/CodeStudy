#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string erase_front_zero(string target) {
    int len = 0;
    while (target[len] == '0') {
        len++;
    }
    if (len == target.length())
        return "0";
    return target.substr(len, target.length());
}
bool compare(string a, string b) {
    if (a.length() == b.length()) {
        int length = a.length();
        for (int i = 0; i < length; i++) {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
    }
    return a.length() < b.length();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int loop;
    cin >> loop;
    vector<string> nums;
    while (loop--) {
        string input;
        cin >> input;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] >= '0' && input[i] <= '9') {
                if (i == input.length() - 1)
                    nums.push_back(input.substr(i, 1));
                else {
                    string to_int;
                    int len = 1;
                    while (i + len < input.length()) {
                        if (input[i + len] >= '0' && input[i + len] <= '9')
                            len++;
                        else
                            break;
                    }
                    nums.push_back(erase_front_zero(input.substr(i, len)));
                    i += len;
                }
            }
        }
    }
    sort(nums.begin(), nums.end(), compare);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << '\n';
    return 0;
}
