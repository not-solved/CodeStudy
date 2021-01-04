#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        triangle[i][0] += triangle[i - 1][0];
        if (answer < triangle[i][0])
            answer = triangle[i][0];
        for (int j = 1; j < triangle[i].size() - 1; j++) {
            triangle[i][j] += (triangle[i - 1][j - 1] > triangle[i - 1][j] ? triangle[i - 1][j - 1] : triangle[i - 1][j]);
            if (answer < triangle[i][j])
                answer = triangle[i][j];
        }
        triangle[i][i] += triangle[i - 1][i - 1];
        if (answer < triangle[i][i])
            answer = triangle[i][i];
    }
    return answer;
}