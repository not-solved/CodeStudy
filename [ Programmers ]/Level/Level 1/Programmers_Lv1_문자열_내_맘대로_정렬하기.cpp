#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<vector<string>> Sort(26);
    for (int i = 0; i < strings.size(); i++) {
        Sort[strings[i][n] - 97].push_back(strings[i]);
    }
    for (int i = 0; i < 26; i++)
        if (!Sort[i].empty())
            sort(Sort[i].begin(), Sort[i].end());
    for (int i = 0; i < 26; i++) {
        if (!Sort[i].empty()) {
            for (int j = 0; j < Sort[i].size(); j++)
                answer.push_back(Sort[i][j]);
        }
    }
    return answer;
}