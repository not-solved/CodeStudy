#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int sum = i;
        if (sum < n) {
            int j = i + 1;
            while (sum + j <= n) {
                sum += j;
                j++;
            }
        }
        if (sum == n)
            answer++;
    }
    return answer;
}