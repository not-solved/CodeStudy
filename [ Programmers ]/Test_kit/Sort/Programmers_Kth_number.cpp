#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int loops = commands.size();
    for (int i = 0; i < loops; i++) {
        vector<int> temp;
        int first = commands[i][0] - 1;
        int last = commands[i][1] - 1;
        for (int j = first; j <= last; j++) {
            temp.push_back(array[j]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2] - 1]);
    }
    return answer;
}