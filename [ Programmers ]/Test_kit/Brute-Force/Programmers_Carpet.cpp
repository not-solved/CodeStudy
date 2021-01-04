#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int Area = brown + yellow;
    int horizon, vertical = 3;
    while (true) {
        horizon = Area / vertical;
        int temp_b = brown - (vertical * 2 + (horizon - 2) * 2);
        if (temp_b >= 0 && temp_b + yellow == (vertical - 2) * (horizon - 2))
            break;
        vertical++;
    }
    answer.push_back(horizon);
    answer.push_back(vertical);
    return answer;
}