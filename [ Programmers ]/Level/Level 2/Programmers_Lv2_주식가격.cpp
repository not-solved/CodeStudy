#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> stock;
    int day;
    for (int i = prices.size() - 2; i >= 0; i--) {
        day = 0;
        while (!stock.empty() && stock.top().first >= prices[i]) {
            day += stock.top().second;
            stock.pop();
        }
        stock.push(make_pair(prices[i], day + 1));
        answer[i] = day + 1;
    }
    return answer;
}