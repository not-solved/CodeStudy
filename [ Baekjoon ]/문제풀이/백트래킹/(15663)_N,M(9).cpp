#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int Numbers[9], visited[9];
vector<int> result;

void calculate(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    int temp_num = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (temp_num == Numbers[i])
                continue;
            temp_num = Numbers[i];
            result.push_back(temp_num);
            visited[i] = 1;
            calculate(idx + 1);
            result.pop_back();
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> Numbers[i];
    sort(Numbers, Numbers + n);
    calculate(0);
    return 0;
}