#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int n = arr1.size();
    int m = arr1[0].size();
    int l = arr2[0].size();

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < l; j++) {
            int sum = 0;
            for (int k = 0; k < m; k++)
                sum += arr1[i][k] * arr2[k][j];
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    return answer;
}