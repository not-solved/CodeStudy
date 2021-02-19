#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<pair<int, int>> S;
    int num, height;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> height;
        while (!S.empty()) {
            if (height < S.top().second) {
                cout << S.top().first << ' ';
                break;
            }
            S.pop();
        }
        if (S.empty())
            cout << 0 << ' ';
        
        S.push(make_pair(i + 1, height));
    }
    return 0;
}
