#include <string>
using namespace std;

string solution(int n) {
    string answer = "";
    int div = 1, rem = 0;
    while (n > 0) {
        div *= 3;
        rem = (n % div == 0 ? div : n % div);
        n -= rem;
        if (rem <= 1 * div / 3) {
            answer = "1" + answer;
            continue;
        }
        if (rem <= 2 * div / 3) {
            answer = "2" + answer;
            continue;
        }
        if (rem <= 3 * div / 3) {
            answer = "4" + answer;
            continue;
        }
    }
    return answer;
}