#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;
vector<int> Comb;
bool used[10001];
int N, M;

void combination(int temp) {
    if (temp >= M) {
        for (int i = 0; i < Comb.size(); i++) {
            cout << Comb[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!used[numbers[i]]) {
            used[numbers[i]] = true;
            Comb.push_back(numbers[i]);
            combination(temp + 1);
            Comb.pop_back();
            used[numbers[i]] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());
    combination(0);
    return 0;
}