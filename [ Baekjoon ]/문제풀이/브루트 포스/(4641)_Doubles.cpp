#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int total = 0;

void calculate(vector<int> list) {
    for (int i = 0; i < list.size(); i++) {
        for (int j = i + 1; j < list.size(); j++) {
            if (list[j] == 2 * list[i]) {
                total++;
                break;
            }
            else if (list[j] > 2 * list[i])
                break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int com;
    do {
        vector<int> List;
        total = 0;
        do {
            cin >> com;
            if (com == 0)
                break;
            else if (com == -1)
                return 0;
            List.push_back(com);
        } while (true);
        sort(List.begin(), List.end());
        calculate(List);
        cout << total << '\n';
    } while (true);
    return 0;
}