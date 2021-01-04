#include <string>
#include <vector>

int Fibonacci[100001];

using namespace std;

int solution(int n) {
    Fibonacci[0] = 0;
    Fibonacci[1] = 1;
    for (int i = 2; i <= n; i++)
        Fibonacci[i] = (Fibonacci[i - 1] + Fibonacci[i - 2]) % 1234567;
    return Fibonacci[n];
}