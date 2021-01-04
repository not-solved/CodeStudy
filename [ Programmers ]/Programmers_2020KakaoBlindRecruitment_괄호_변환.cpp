#include <string>
#include <vector>
#include <stack>
using namespace std;

// 문자열을 u, v로 나누는 함수
pair<string, string> split_uv(string s) {
    int left = 0, right = 0, bound = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            left++;
        else
            right++;
        bound++;
        if (left == right)
            break;
    }
    string U = s.substr(0, bound), V = "";
    if (U.length() < s.length());
    V = s.substr(bound, s.length());
    return make_pair(U, V);
}

// "올바른 괄호 문자열"인지 판별하는 함수
bool check(string target) {
    if (target == "")
        return true;
    int count = 0;
    for (int i = 0; i < target.length(); i++) {
        if (target[i] == '(')
            count++;
        else
            count--;
        if (count <= -1)
            return false;
    }
    return true;
}

// "올바르지 않은 문자열"인 U를 올바른 문자열로 변환하는 함수
string reconstruct(string target) {
    if (target == "")
        return "";
    string result = target;
    for (int i = 0; i < result.length(); i++) {
        if (result[i] == ')')
            result[i] = '(';
        else
            result[i] = ')';
    }
    return result;
}

// 재귀함수
string calculate(string target) {
    if (target == "")
        return "";
    pair<string, string> Split = split_uv(target);
    string U = Split.first, V = Split.second;
    if (!check(U))
        return "(" + calculate(V) + ")" + reconstruct(U.substr(1, U.length() - 2));
    return U + calculate(V);
}

string solution(string p) {
    if (check(p))
        return p;
    return calculate(p);
}