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
            begin_idx = i;          // 시작단어 인덱스
        if (words[i] == target)
            target_idx = i;         // 타겟단어 인덱스

        for (int j = i + 1; j < words.size(); j++) {
            int diff_chars = 0;
            for (int a = 0; a < begin.length(); a++)
                if (words[i][a] != words[j][a])
                    diff_chars++;
            if (diff_chars == 1) {   // 도달할 수 있는 단어 추가
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    // 없는 단어를 찾으려하는 경우
    if (target_idx == -1)
        return 0;

    // 단어 목록에 시작단어가 없을 경우, 도달할 수 있는 단어를 추가
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
    // BFS 시작
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
    // 단어 목록에 타겟이 있음에도 도달 못하는 경우
    return 0;
}