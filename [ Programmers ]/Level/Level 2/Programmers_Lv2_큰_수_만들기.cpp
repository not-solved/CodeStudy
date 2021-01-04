#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    if (number.length() < k)
        return "";
    while (k > 0) {
        bool finish = false;
        for (int i = 0; i < number.length(); i++) {
            if (number[i] < number[i + 1]) {
                number.erase(i, 1);
                k--;
                finish = true;
                break;
            }
        }
        if (!finish) {
            number = number.substr(0, number.length() - k);
            break;
        }
    }
    return number;
}