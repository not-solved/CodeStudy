#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dice[4];
int price() {
    int max_dice = 0, result = 0, difference = 4;
    int log[7] = { 0, 0, 0, 0, 0, 0, 0 };
    vector<int> dice_log;
    for (int i = 0; i < 4; i++) {
        cin >> dice[i];
        if (log[dice[i]] == 0) {
            dice_log.push_back(dice[i]);
            difference--;
        }
        log[dice[i]]++;
        if (max_dice < dice[i])
            max_dice = dice[i];
    }
    if (dice_log.size() == 1)
        result = 50000 + dice_log[0] * 5000;
    else if (dice_log.size() == 2) {
        if (log[dice_log[0]] == 3)
            result = 10000 + dice_log[0] * 1000;
        else if (log[dice_log[0]] == 1)
            result = 10000 + dice_log[1] * 1000;
        else
            result = 2000 + (dice_log[0] + dice_log[1]) * 500;
    }
    else if (dice_log.size() == 3) {
        for (int i = 0; i < 3; i++) {
            if (log[dice_log[i]] == 2)
                result = 1000 + dice_log[i] * 100;
        }
    }
    else {
        result = max_dice * 100;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int loop, Max = 0;
    cin >> loop;
    while (loop--) {
        Max = max(price(), Max);
    }
    cout << Max;
    return 0;
}