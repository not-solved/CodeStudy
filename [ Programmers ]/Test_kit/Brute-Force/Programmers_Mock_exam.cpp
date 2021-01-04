#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int s1[5] = { 1, 2, 3, 4, 5 };
int s2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int s3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int index1 = 0, index2 = 0, index3 = 0;
    int score1 = 0, score2 = 0, score3 = 0;

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == s1[index1])
            score1++;
        if (answers[i] == s2[index2])
            score2++;
        if (answers[i] == s3[index3])
            score3++;
        index1 = (index1 + 1) % 5;
        index2 = (index2 + 1) % 8;
        index3 = (index3 + 1) % 10;
    }
    if (score1 == score2 && score1 == score3) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    else if (score1 >= score2 && score1 >= score3) {
        answer.push_back(1);
        if (score1 == score2)
            answer.push_back(2);
        if (score1 == score3)
            answer.push_back(3);
    }
    else if (score2 > score1&& score2 >= score3) {
        answer.push_back(2);
        if (score2 == score3)
            answer.push_back(3);
    }
    else if (score3 > score1&& score3 > score2)
        answer.push_back(3);

    return answer;
}