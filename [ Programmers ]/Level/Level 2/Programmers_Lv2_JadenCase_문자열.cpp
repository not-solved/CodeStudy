
#include <string>
#include <vector>

using namespace std;

vector<string> Split(string s) {
    vector<string> result;
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            result.push_back(temp);
            temp = "";
        }
        else
            temp = temp + s[i];
    }
    result.push_back(temp);
    return result;
}

string JadenCase(string s) {
    string result = s;
    for (int i = 0; i < s.length(); i++) {
        if (i == 0)
            result[i] = toupper(result[i]);
        else
            result[i] = tolower(result[i]);
    }
    return result;
}

string solution(string s) {
    string answer = "";
    vector<string> words = Split(s);
    for (int i = 0; i < words.size(); i++) {
        words[i] = JadenCase(words[i]);
        answer += words[i] + " ";
    }
    answer = answer.substr(0, answer.length() - 1);
    return answer;
}