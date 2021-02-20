#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    int monsters, questions, idx, begin, end;
    cin >> monsters >> questions;
    vector<pair<string, int>> name;
    vector<string> number;
    string input;
    for (int i = 1; i <= monsters; i++) {
        cin >> input;
        name.push_back({input, i});
        number.push_back(input);
    }
    sort(name.begin(), name.end());

    while (questions--) {
        cin >> input;
        if (input[0] >= 'A') {
            begin = 0;
            end = monsters - 1;
            while (begin <= end) {
                int mid = (begin + end) / 2;

                if (name[mid].first == input) {
                    cout << name[mid].second << '\n';
                    break;
                }
                else if (name[mid].first < input)
                    begin = mid + 1;
                else if (name[mid].first > input)
                    end = mid - 1;
            }
        }
        else {
            idx = stoi(input);
            cout << number[idx - 1] << '\n';
        }
    }
    return 0;
}