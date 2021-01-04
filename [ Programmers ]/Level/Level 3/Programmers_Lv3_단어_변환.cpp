#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int target_idx = -1, begin_idx = words.size();
    vector<vector<int>> graph(begin_idx + 1);
    vector<bool> visited(begin_idx + 1);
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == begin)
            begin_idx = i;          // ���۴ܾ� �ε���
        if (words[i] == target)
            target_idx = i;         // Ÿ�ٴܾ� �ε���

        for (int j = i + 1; j < words.size(); j++) {
            int diff_chars = 0;
            for (int a = 0; a < begin.length(); a++)
                if (words[i][a] != words[j][a])
                    diff_chars++;
            if (diff_chars == 1) {   // ������ �� �ִ� �ܾ� �߰�
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    // ���� �ܾ ã�����ϴ� ���
    if (target_idx == -1)
        return 0;

    // �ܾ� ��Ͽ� ���۴ܾ ���� ���, ������ �� �ִ� �ܾ �߰�
    if (begin_idx == words.size()) {
        for (int i = 0; i < begin_idx; i++) {
            int diff_chars = 0;
            for (int a = 0; a < begin.length(); a++) {
                if (words[i][a] != begin[a])
                    diff_chars++;
            }
            if (diff_chars == 1) {
                graph[begin_idx].push_back(i);
                graph[i].push_back(begin_idx);
            }
        }
    }
    int depth = 1;
    queue<int> BFS;
    BFS.push(begin_idx);
    visited[begin_idx] = true;
    // BFS ����
    while (!BFS.empty()) {
        int size = BFS.size();
        for (int loop = 0; loop < size; loop++) {
            int temp = BFS.front();
            for (int i = 0; i < graph[temp].size(); i++) {
                if (target_idx == graph[temp][i]) {
                    return depth;
                }
                if (!visited[graph[temp][i]]) {
                    visited[graph[temp][i]] = true;
                    BFS.push(graph[temp][i]);
                }
            }
            BFS.pop();
        }
        depth++;
    }
    // �ܾ� ��Ͽ� Ÿ���� �������� ���� ���ϴ� ���
    return 0;
}