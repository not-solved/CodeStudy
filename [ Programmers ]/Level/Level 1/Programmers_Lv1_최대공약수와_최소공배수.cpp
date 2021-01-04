#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int greater, smaller;
    if (n > m) {
        greater = n;
        smaller = m;
    }
    else {
        greater = m;
        smaller = n;
    }
    int LCD = 1;
    for (int i = 2; i <= smaller; i++) {
        if (smaller % i == 0 && greater % i == 0)
            LCD = i;
    }
    int GCD = greater * smaller / LCD;
    answer.push_back(LCD);
    answer.push_back(GCD);
    return answer;
}