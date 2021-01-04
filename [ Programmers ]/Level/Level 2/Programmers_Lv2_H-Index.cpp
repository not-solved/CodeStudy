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
        // 1. �� �´� H-index�� ã���� ��
        if (temp == i) {
            return temp;
        }
        // 2. h���� �ο���� �������� ���������� ������ ������ H-index
        else if (temp < i) {
            return i - 1;
        }
        Sort.pop();
    }

    // 3. ��� �� �ο� Ƚ���� �� �� ���� ������ �� ���� H-index
    if (temp >= size)
        return size;
}