#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000000;

int op[4];
int Max = -1 * MAX;
int Min = MAX;

void calculate(vector<int> N, int operators, int index, int result) {
    if (operators <= 0) {
        if (result > Max)
            Max = result;
        if (result < Min)
            Min = result;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            if (i == 0)
                calculate(N, operators - 1, index + 1, result + N[index]);
            else if (i == 1)
                calculate(N, operators - 1, index + 1, result - N[index]);
            else if (i == 2)
                calculate(N, operators - 1, index + 1, result * N[index]);
            else if (i == 3)
                calculate(N, operators - 1, index + 1, result / N[index]);
            op[i]++;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int numbers;
    cin >> numbers;

    vector<int> N(numbers);
    for (int i = 0; i < numbers; i++)
        cin >> N[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];
    calculate(N, numbers - 1, 1, N[0]);
    cout << Max << '\n' << Min;
    return 0;
}

