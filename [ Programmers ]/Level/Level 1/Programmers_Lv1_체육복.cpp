#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    int res[31] = { 0, };

    sort(lost.begin(), lost.end());
    for (int i = 0; i < lost.size(); i++)
        res[lost[i]] = 1;

    sort(reserve.begin(), reserve.end());
    for (int i = 0; i < reserve.size(); i++) {
        if (res[reserve[i]] == 1) {
            res[reserve[i]] = 3;
            answer++;
        }
        else
            res[reserve[i]] = 2;
    }

    for (int i = 0; i < lost.size(); i++) {
        if (res[lost[i]] == 1 && res[lost[i] - 1] == 2) {
            res[lost[i] - 1] = 3;
            res[lost[i]] = 0;
            answer++;
        }
        else if (res[lost[i]] == 1 && res[lost[i] + 1] == 2) {
            res[lost[i] + 1] = 3;
            res[lost[i]] = 0;
            answer++;
        }
    }
    return answer;
}