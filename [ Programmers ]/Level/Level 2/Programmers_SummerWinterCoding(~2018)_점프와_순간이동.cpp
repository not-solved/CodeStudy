#include <iostream>
using namespace std;

int solution(int n) {
    int ans = 1;    // �⺻ ���� 1ȸ
    while (n > 1) {
        // �����̵��� �ϸ� 2����θ� �̵��ϹǷ�, 2�� ������������ ���� ��� 1ȸ �����ϴ� ������ ���
        if (n % 2 == 1)
            ans++;
        n /= 2;
    }
    return ans;
}