#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> N, result;
    string input;
    while (n--) {
        cin >> input;
        N.push_back(input);
    }
    sort(N.begin(), N.end());
    while (m--) {
        cin >> input;
        int front = 0, back = N.size() - 1, mid;
        while (front <= back) {
            mid = (front + back) / 2;
            if (N[mid] == input) {
                result.push_back(N[mid]);
                break;
            }
            else if (N[mid] < input)
                front = mid + 1;
            else if (N[mid] > input)
                back = mid - 1;
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';
    
    return 0;
}