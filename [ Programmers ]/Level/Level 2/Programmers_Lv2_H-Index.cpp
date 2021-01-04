#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    priority_queue<int> Sort;
    for (int i = 0; i < citations.size(); i++)
        Sort.push(citations[i]);

    int answer = 0;

    int size = citations.size(), temp = 0;
    for (int i = 1; i <= size; i++) {
        temp = Sort.top();
        // 1. 딱 맞는 H-index를 찾았을 때
        if (temp == i) {
            return temp;
        }
        // 2. h보다 인용수가 적어지는 시점에서는 이전의 갯수가 H-index
        else if (temp < i) {
            return i - 1;
        }
        Sort.pop();
    }

    // 3. 모든 논문 인용 횟수가 논문 수 보다 많으면 논문 수가 H-index
    if (temp >= size)
        return size;
}