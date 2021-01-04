#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s) {
    if (s[0] == ')' || s[s.length() - 1] == '(')
        return false;
    stack<char> S;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            S.push(s[i]);
        else if (s[i] == ')') {
            if (S.empty())
                return false;
            S.pop();
        }
    }
    if (S.empty())
        return true;
    else
        return false;
}