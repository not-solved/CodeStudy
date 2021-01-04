#include <iostream>
#include <vector>
using namespace std;

int get_max(vector<int> stage, int current, int ban_index) {
    int temp = 0;
    for (int i = 0; i < 4; i++) {
        if (i == ban_index)
            continue;
        if (temp < stage[i] + current)
            temp = stage[i] + current;
    }
    return temp;
}

int solution(vector<vector<int> > land) {
    int temp = 0, ban = 0, index = 0;
    vector<vector<int>> dp = land;
    for (int i = 1; i < land.size(); i++)
        for (int j = 0; j < 4; j++)
            land[i][j] = get_max(land[i - 1], land[i][j], j);

    for (int i = 0; i < 4; i++)
        if (temp < land[land.size() - 1][i])
            temp = land[land.size() - 1][i];
    return temp;
}