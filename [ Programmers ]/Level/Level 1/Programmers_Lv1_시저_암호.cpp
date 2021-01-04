#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = s;
    for (int i = 0; i < answer.length(); i++) {
        if (answer[i] >= 'A' && answer[i] <= 'Z') {
            if (answer[i] + n <= 'Z')
                answer[i] += n;
            else
                answer[i] = 64 + (answer[i] + n - 'Z');
        }
        else if (answer[i] >= 'a' && answer[i] <= 'z') {
            if (answer[i] + n <= 'z')
                answer[i] += n;
            else
                answer[i] = 96 + (answer[i] + n - 'z');
        }
    }
    return answer;
}