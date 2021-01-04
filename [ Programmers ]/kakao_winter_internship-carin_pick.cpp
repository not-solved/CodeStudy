#include <string>
#include <stack>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board[0].size();
    stack<int> basket;
    for (int i = 0; i < moves.size(); i++) {
        int current = moves[i] - 1;
        int pick = 0;
        for (int j = 0; j < size; j++) {
            if (board[j][current] != 0) {
                pick = board[j][current];
                board[j][current] = 0;
                break;
            }
        }
        if (pick == 0)
            continue;
        if (basket.empty() || basket.top() != pick)
            basket.push(pick);
        else if (basket.top() == pick) {
            basket.pop();
            answer += 2;
        }
    }
    return answer;
}