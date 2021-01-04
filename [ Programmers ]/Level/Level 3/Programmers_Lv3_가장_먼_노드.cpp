#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    queue<int> seq;
    seq.push(1);
    while (!seq.empty()) {
        int size = seq.size();
        answer = size;
        while (size--) {
            visited[seq.front()] = true;
            for (int i = 0; i < graph[seq.front()].size(); i++) {
                if (!visited[graph[seq.front()][i]]) {
                    visited[graph[seq.front()][i]] = true;
                    seq.push(graph[seq.front()][i]);
                }
            }
            seq.pop();
        }
    }
    return answer;
}