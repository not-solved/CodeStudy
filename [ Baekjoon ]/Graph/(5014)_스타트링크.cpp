#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int height, start, terminate, up, down;
    cin >> height >> start >> terminate >> up >> down;

    queue<pair<int, int>> BFS_slot;
    vector<int> building(height + 1);
    BFS_slot.push(make_pair(start, 0));
    int temp, m_cnt;
    while (!BFS_slot.empty() && building[terminate] == 0) {
        temp = BFS_slot.front().first;
        m_cnt = BFS_slot.front().second;
        BFS_slot.pop();
        if (temp + up <= height && building[temp + up] == 0) {
            building[temp + up] = m_cnt + 1;
            BFS_slot.push(make_pair(temp + up, m_cnt + 1));
        }
        if (temp - down > 0 && building[temp - down] == 0) {
            building[temp - down] = m_cnt + 1;
            BFS_slot.push(make_pair(temp - down, m_cnt + 1));
        }
    }
    if (building[terminate] == 0 && start != terminate)
        cout << "use the stairs";
    else
        cout << building[terminate];

    return 0;
}