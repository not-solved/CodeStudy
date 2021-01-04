#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> L_position = make_pair(1, 3);
    pair<int, int> R_position = make_pair(3, 3);

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 3 == 2 || numbers[i] == 0) {
            int target = (numbers[i] == 0 ? 10 : numbers[i]);

            int Ldist = abs((target / 3) - L_position.second);
            if (L_position.first != 2)
                Ldist++;

            int Rdist = abs((target / 3) - R_position.second);
            if (R_position.first != 2)
                Rdist++;

            if (Ldist < Rdist) {
                answer += 'L';
                L_position = make_pair(2, target / 3);
            }
            else if (Ldist > Rdist) {
                answer += 'R';
                R_position = make_pair(2, target / 3);
            }
            else {
                if (hand == "left") {
                    answer += 'L';
                    L_position = make_pair(2, target / 3);
                }
                else {
                    answer += 'R';
                    R_position = make_pair(2, target / 3);
                }
            }
        }
        else if (numbers[i] % 3 == 1) {
            answer += 'L';
            L_position = make_pair(1, (numbers[i] - 1) / 3);
        }
        else if (numbers[i] % 3 == 0) {
            answer += 'R';
            R_position = make_pair(3, (numbers[i] - 1) / 3);
        }
    }
    return answer;
}