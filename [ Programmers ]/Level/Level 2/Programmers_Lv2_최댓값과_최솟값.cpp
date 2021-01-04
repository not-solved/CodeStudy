#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> numbers;
    int i = 0;
    while (i < s.length()) {
        int flag = 1;
        if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-') {
            if (s[i] == '-') {
                flag = -1;
                i++;
            }
            int temp = 0;
            while (s[i] != ' ' && i < s.length()) {
                temp *= 10;
                temp += s[i++] - 48;
            }
            numbers.push_back(flag * temp);
        }
        else
            i++;
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << ' ';
    answer += to_string(numbers[0]);
    answer += " " + to_string(numbers[numbers.size() - 1]);
    return answer;
}