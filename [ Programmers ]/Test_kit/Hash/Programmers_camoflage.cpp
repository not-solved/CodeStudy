#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    vector<vector<string>> comb(30);
    int cloth = 0;
    for (int i = 0; i < clothes.size(); i++) {
        if (comb[0].size() <= 0) {
            comb[0].push_back(clothes[i][1]);
            comb[0].push_back(clothes[i][0]);
            cloth++;
        }
        else {
            bool find = false;
            for (int j = 0; j < cloth; j++) {
                if (comb[j][0] == clothes[i][1]) {
                    comb[j].push_back(clothes[i][0]);
                    find = true;
                    break;
                }
            }
            if (!find) {
                comb[cloth].push_back(clothes[i][1]);
                comb[cloth].push_back(clothes[i][0]);
                cloth++;
            }
        }
    }
    int temp = 1;
    for (int i = 0; i < cloth; i++)
        temp *= (comb[i].size());
    answer += temp;

    return answer - 1;
}