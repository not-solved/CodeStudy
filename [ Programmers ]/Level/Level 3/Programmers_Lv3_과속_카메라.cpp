#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    // ������ �������� �������� ���� --> ���� ���� �������� ��
    sort(routes.begin(), routes.end());

    // �ּ� 1���� ������ ����
    int answer = 1;
    int temp_front = routes[0][0], temp_back = routes[0][1];

    for (int i = 1; i < routes.size(); i++) {
        if (temp_back > routes[i][1])        // ���� ���� ���ο� �ִٸ�
            temp_back = routes[i][1];       // ���� ������ ���
        else if (temp_back < routes[i][0]) {
            answer++;
            temp_front = routes[i][0];      // ���� ������ ��ġ�� ������
            temp_back = routes[i][1];       // ���� ���� ����
        }
    }
    return answer;
}