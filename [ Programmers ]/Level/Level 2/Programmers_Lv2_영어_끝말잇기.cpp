#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<vector<string>> history(26);

    int turn = 2;
    int count = 1;
    string temp = words[0];
    history[words[0][0] - 97].push_back(words[0]);

    for (int i = 1; i < words.size(); i++) {
        if (temp[temp.length() - 1] != words[i][0]) {
            answer.push_back(turn);
            answer.push_back(count);
            return answer;
        }
        if (history[words[i][0] - 97].empty())
            history[words[i][0] - 97].push_back(words[i]);
        else {
            for (int j = 0; j < history[words[i][0] - 97].size(); j++) {
                if (words[i] == history[words[i][0] - 97][j]) {
                    answer.push_back(turn);
                    answer.push_back(count);
                    return answer;
                }
            }
            history[words[i][0] - 97].push_back(words[i]);
        }
        temp = words[i];
        turn = (turn % n) + 1;
        if ((i + 1) % n == 0)
            count++;
    }
    if (answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}