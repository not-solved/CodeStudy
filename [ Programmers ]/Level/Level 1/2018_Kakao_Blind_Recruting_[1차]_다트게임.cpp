#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> scoreboard;
    int score, s_index = 0, b_index = -1;
    while (s_index < dartResult.length()) {
        score = dartResult[s_index] - 48;
        if (dartResult[s_index + 1] == '0') {
            score = 10;
            s_index++;
        }

        if (dartResult[s_index + 1] == 'D')
            score = pow(score, 2);
        else if (dartResult[s_index + 1] == 'T')
            score = pow(score, 3);

        if (dartResult[s_index + 2] == '*') {
            score *= 2;
            s_index++;
            if (!scoreboard.empty())
                scoreboard[b_index] *= 2;
        }
        else if (dartResult[s_index + 2] == '#') {
            score *= -1;
            s_index++;
        }
        cout << score << ' ';
        scoreboard.push_back(score);
        s_index += 2;
        b_index++;
    }
    cout << endl;
    for (int i = 0; i < scoreboard.size(); i++) {
        cout << scoreboard[i] << ' ';
        answer += scoreboard[i];
    }
    return answer;
}