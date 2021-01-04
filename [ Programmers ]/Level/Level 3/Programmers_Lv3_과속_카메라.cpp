#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    // 차량의 진입지점 기준으로 정렬 --> 진출 지점 기준으로 비교
    sort(routes.begin(), routes.end());

    // 최소 1대의 차량이 존재
    int answer = 1;
    int temp_front = routes[0][0], temp_back = routes[0][1];

    for (int i = 1; i < routes.size(); i++) {
        if (temp_back > routes[i][1])        // 기준 구간 내부에 있다면
            temp_back = routes[i][1];       // 기준 구간을 축소
        else if (temp_back < routes[i][0]) {
            answer++;
            temp_front = routes[i][0];      // 기준 구간과 겹치지 않으면
            temp_back = routes[i][1];       // 기준 구간 갱신
        }
    }
    return answer;
}