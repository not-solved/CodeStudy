#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool desc(int a, int b) {
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<pair<int, int>> in_list;
    vector<int> Priority;
    for (int i = 0; i < priorities.size(); i++) {
        in_list.push(make_pair(priorities[i], i));
        Priority.push_back(priorities[i]);
    }
    sort(Priority.begin(), Priority.end(), desc);

    int index = 0;
    while (!in_list.empty()) {
        if (Priority[index] == in_list.front().first) {
            if (in_list.front().second == location)
                return answer;
            else {
                in_list.pop();
                index++;
                answer++;
            }
        }
        else {
            pair<int, int> temp = in_list.front();
            in_list.pop();
            in_list.push(temp);
        }
    }
    return answer;
}