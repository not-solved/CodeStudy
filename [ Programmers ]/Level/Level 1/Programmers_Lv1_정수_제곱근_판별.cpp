#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long temp = sqrt(n);
    if (n == temp * temp)
        return (temp + 1) * (temp + 1);
    else
        return -1;
}