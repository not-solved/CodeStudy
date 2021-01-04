#include <string>
#include <vector>
#include <stack>
using namespace std;

// ���ڿ��� u, v�� ������ �Լ�
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

// "�ùٸ� ��ȣ ���ڿ�"���� �Ǻ��ϴ� �Լ�
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

// "�ùٸ��� ���� ���ڿ�"�� U�� �ùٸ� ���ڿ��� ��ȯ�ϴ� �Լ�
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

// ����Լ�
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