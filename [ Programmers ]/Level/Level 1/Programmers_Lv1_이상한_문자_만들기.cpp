#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = s;
    int index = 0;
    for (int i = 0; i < answer.length(); i++) {
        if (answer[i] == ' ') {
            index = 0;
            continue;
        }
        if (index % 2 == 0) {
            answer[i] = toupper(answer[i]);
        }
        else {
            answer[i] = tolower(s[i]);
        }
        index++;
    }
    return answer;
}