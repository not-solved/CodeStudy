#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<double, int>& a, pair<double, int>& b) {
    if (a.first != b.first)
        return a.first > b.first;       // �������� �ٸ��� ��������
    else
        return a.second < b.second;     // �������� ������ ���� �� ������ ��������
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(), stages.end());

    vector<double> Fail_count(N + 1, 0);
    vector<pair<double, int>> Fail_rate;

    for (int i = 0; i < stages.size(); i++) {
        if (stages[i] <= N)
            Fail_count[stages[i]]++;
    }
    int people = stages.size();
    for (int i = 0; i < N; i++) {
        if (people > 0) {
            Fail_rate.push_back(make_pair((Fail_count[i + 1] / people), i + 1));
            people -= Fail_count[i + 1];
        }
        else
            Fail_rate.push_back(make_pair(0, i + 1));
    }

    sort(Fail_rate.begin(), Fail_rate.end(), cmp);
    for (int i = 0; i < Fail_rate.size(); i++) {
        answer.push_back(Fail_rate[i].second);
    }
    return answer;
}