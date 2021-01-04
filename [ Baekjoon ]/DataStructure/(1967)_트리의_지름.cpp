#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int length = 0;
int Vertex_no = 0;
vector<vector<pair<int, int>>> tree(100001);
bool visited[100001] = { 0, };

void calculate(int index, int weight) {
    if (visited[index])
        return;
    visited[index] = true;

    if (weight > length) {
        length = weight;
        Vertex_no = index;
    }
    for (int i = 0; i < tree[index].size(); i++)
        calculate(tree[index][i].first, weight + tree[index][i].second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int nodes, start, end, weight;
    cin >> nodes;
    for (int i = 1; i < nodes; i++) {
        cin >> start >> end >> weight;
        tree[start].push_back(make_pair(end, weight));
        tree[end].push_back(make_pair(start, weight));
    }
    calculate(1, 0);
    length = 0;
    memset(visited, false, sizeof(visited));
    calculate(Vertex_no, 0);
    cout << length;

    return 0;
}
