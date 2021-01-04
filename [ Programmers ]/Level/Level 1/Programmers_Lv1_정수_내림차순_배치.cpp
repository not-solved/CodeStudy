#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(long long n) {
    vector<int> Sorted;
    while (n > 0) {
        Sorted.push_back(n % 10);
        n /= 10;
    }
    sort(Sorted.begin(), Sorted.end());
    long long answer = 0;
    for (int i = Sorted.size() - 1; i >= 0; i--) {
        answer *= 10;
        answer += Sorted[i];
    }
    return answer;
}