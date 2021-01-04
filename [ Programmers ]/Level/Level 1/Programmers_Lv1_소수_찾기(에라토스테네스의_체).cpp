#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    vector<int> primes(1000001, 0);
    int answer = 0;
    for (int i = 2; i <= n; i++) {
        if (primes[i] == 0) {
            answer++;
            for (int j = 1; j * i <= n; j++)
                primes[i * j] = 1;
        }
    }
    return answer;
}