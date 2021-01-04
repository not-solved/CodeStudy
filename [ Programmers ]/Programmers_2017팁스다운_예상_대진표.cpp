#include <iostream>
using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;
    int big = (a > b ? a : b) - 1;
    int small = (a < b ? a : b) - 1;
    while (true) {
        if (big / 2 == small / 2)
            break;
        big /= 2;
        small /= 2;
        answer++;
    }
    return answer + 1;
}