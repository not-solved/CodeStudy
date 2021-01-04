#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> map;
int MAX, x_max, y_max, temp_max;
int xi[4] = { 1, -1, 0, 0 };
int yi[4] = { 0, 0, 1, -1 };
void BFS(int y, int x, int target) {
    if (map[y][x] == 0)
        return;

    map[y][x] = 0;
    temp_max++;
    for (int i = 0; i < 4; i++) {
        if (y + yi[i] < 0 || y + yi[i] >= y_max || x + xi[i] < 0 || x + xi[i] >= x_max)
            continue;
        if (map[y + yi[i]][x + xi[i]] != target)
            continue;
        BFS(y + yi[i], x + xi[i], target);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int area_size = 0;
    map = picture, MAX = 0, x_max = n, y_max = m, temp_max = 0;
    for (int i = 0; i < y_max; i++) {
        for (int j = 0; j < x_max; j++) {
            if (map[i][j] != 0) {
                area_size++;
                temp_max = 0;
                BFS(i, j, map[i][j]);
                if (MAX < temp_max)
                    MAX = temp_max;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = area_size;
    answer[1] = MAX;
    return answer;
}