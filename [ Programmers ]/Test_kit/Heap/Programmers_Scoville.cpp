#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> S;
    for (int i = 0; i < scoville.size(); i++)
        S.push(scoville[i]);

    int sco = 0;
    if (S.top() >= K)
        return 0;

    while (!S.empty() && S.top() < K) {
        if (S.size() == 1)
            return -1;
        sco = S.top();
        S.pop();
        sco += (S.top() * 2);
        S.pop();
        S.push(sco);
        ++answer;
    }
    return answer;
}