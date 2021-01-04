#include <string>
#include <vector>
using namespace std;

void DFS(vector<int> numbers, int temp, int idx, int target) {
    if (idx == numbers.size()) {
        if (temp == target)
            result++;
        return;
    }
    DFS(numbers, temp + numbers[idx], idx + 1, target);
    DFS(numbers, temp - numbers[idx], idx + 1, target);
}

int solution(vector<int> numbers, int target) {
    result = 0;
    DFS(numbers, 0, 0, target);
    return result;
}