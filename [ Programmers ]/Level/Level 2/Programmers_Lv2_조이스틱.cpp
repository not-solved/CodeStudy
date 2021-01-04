#include <string>
#include <vector>

using namespace std;
int Min(char a, char b) {
    return (b - a > a - b + 26 ? a - b + 26 : b - a);
}

int solution(string name) {
    int complete = 1, idx = 0, size = name.length(), answer = Min('A', name[0]);
    name[0] = 'A';
    for (int i = 1; i < name.length(); i++) {
        if (name[i] == 'A')
            complete++;
    }
    int left, right;
    while (complete < name.length()) {
        left = 1, right = 1;
        while (name[(idx - left + size) % size] == 'A') {
            left++;
        }
        while (name[(idx + right) % size] == 'A') {
            right++;
        }
        int left_value = Min('A', name[(idx - left + size) % size]) + left;
        int right_value = Min('A', name[(idx + right) % size]) + right;
        if (left < right) {
            idx = (idx - left + size) % size;
            answer += left_value;
        }
        else {
            idx = (idx + right) % size;
            answer += right_value;
        }
        name[idx] = 'A';
        complete++;
    }
    return answer;
}