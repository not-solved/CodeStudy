#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int front = people.size() - 1, back = 0;
    while (front >= back) {
        if (people[front] + people[back] <= limit) {
            front--;
            back++;
        }
        else
            front--;
        answer++;
    }
    return answer;
}