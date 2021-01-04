#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int date = 0;
    int P = 0;
    for (int i = 0; i < progresses.size(); i++) {
        while (true) {
            if (progresses[i] + speeds[i] * date < 100)
                date++;
            else
                break;
        }
        P = 1;
        while (i + 1 < progresses.size()) {
            if (progresses[i + 1] + speeds[i + 1] * date >= 100) {
                i++;
                P++;
            }
            else
                break;
        }
        answer.push_back(P);
    }
    return answer;
}