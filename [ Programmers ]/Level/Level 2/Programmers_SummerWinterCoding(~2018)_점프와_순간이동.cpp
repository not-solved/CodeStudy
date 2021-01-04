#include <iostream>
using namespace std;

int solution(int n) {
    int ans = 1;    // 기본 점프 1회
    while (n > 1) {
        // 순간이동을 하면 2배수로만 이동하므로, 2로 나눠떨어지지 않을 경우 1회 점프하는 것으로 계산
        if (n % 2 == 1)
            ans++;
        n /= 2;
    }
    return ans;
}