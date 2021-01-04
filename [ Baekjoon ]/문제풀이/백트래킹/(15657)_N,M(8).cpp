#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Number;
vector<int> slot;

void calculate(int idx, int Count, int Size) {
    if (Count >= Size) {
        for (int i = 0; i < Size; i++) {
            cout << slot[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = idx; i < Number.size(); i++) {
        slot.push_back(Number[i]);
        calculate(i, Count + 1, Size);
        slot.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, num;
    cin >> n >> m;
    bool visited[10001] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (!visited[num]) {
            visited[num] = true;
            Number.push_back(num);
        }
    }
    sort(Number.begin(), Number.end());
    calculate(0, 0, m);

    return 0;
}