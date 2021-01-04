#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    vector<vector<string>> hashtable(26);
    for (int i = 0; i < completion.size(); i++) {
        hashtable[completion[i][0] - 97].push_back(completion[i]);
    }
    for (int i = 0; i < participant.size(); i++) {
        int index = participant[i][0] - 97;
        int count = 0;
        if (hashtable[index].size() == 0)
            return participant[i];

        for (int j = 0; j < hashtable[index].size(); j++) {
            if (hashtable[index][j] == participant[i]) {
                hashtable[index][j] = "";
                break;
            }
            else
                count++;
        }
        if (count >= hashtable[index].size())
            return participant[i];
    }
    return "fault";
}