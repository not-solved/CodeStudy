#include <string>
#include <stack>
using namespace std;

char stk[1000001];

int solution(string s) {
    int idx = 0;
    stk[idx++] = s[0];
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == stk[idx - 1]) {
            stk[idx--] = ' ';
        }
        else {
            stk[idx++] = s[i];
        }
    }
    if (idx <= 0)
        return 1;
    else
        return 0;
}