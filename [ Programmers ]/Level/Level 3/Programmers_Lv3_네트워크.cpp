#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[201];
void DFS(vector<vector<int>> network, int computer_no) {
    for (int i = 0; i < network[computer_no].size(); i++) {
        if (!visited[network[computer_no][i]]) {
            visited[network[computer_no][i]] = true;
            cout << network[computer_no][i] << ' ';
            DFS(network, network[computer_no][i]);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int networks = 0;
    vector<vector<int>> network(n + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (computers[i][j] && i != j)
                network[i + 1].push_back(j + 1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            DFS(network, i);
            networks++;
        }
    }
    return networks;
}