#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> ID_name;
    map<string, vector<int>> ID_log;

    char com;
    string id, name;
    for (int i = 0; i < record.size(); i++) {
        com = record[i][0];
        if (com == 'C')
            record[i] = record[i].substr(7, 21);
        else
            record[i] = record[i].substr(6, 21);

        for (int a = 0; a < record[i].length(); a++) {
            if (a == record[i].length() - 1) {
                id = record[i].substr(0, 10);
                break;
            }
            else if (record[i][a] == ' ') {
                id = record[i].substr(0, a);
                name = record[i].substr(a + 1, 10);
                break;
            }
        }
        switch (com) {
        case 'E':
            if (ID_name.find(id) != ID_name.end()) {
                ID_name[id] = name;
                ID_log[id].push_back(answer.size());
            }
            else {
                ID_name.insert(make_pair(id, name));
                vector<int> temp(1, answer.size());
                ID_log.insert(make_pair(id, temp));
            }
            answer.push_back("´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
            break;
        case 'L':
            ID_log[id].push_back(answer.size());
            answer.push_back("´ÔÀÌ ³ª°¬½À´Ï´Ù.");
            break;
        case 'C':
            ID_name[id] = name;
        }
    }
    for (auto iter = ID_name.begin(); iter != ID_name.end(); iter++) {
        id = iter->first;
        name = iter->second;
        for (int j = 0; j < ID_log[id].size(); j++) {
            answer[ID_log[id][j]] = name + answer[ID_log[id][j]];
        }
    }
    return answer;
}