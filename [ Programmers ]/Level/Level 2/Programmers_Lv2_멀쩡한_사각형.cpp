#include <iostream>
using namespace std;

long long get_GCD(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return get_GCD(b, a % b);
}

long long solution(int w, int h) {
    unsigned long long Area = (long long)w * (long long)h;
    unsigned long long Broken = (long long)w + (long long)h - get_GCD(w, h);
    return Area - Broken;
}