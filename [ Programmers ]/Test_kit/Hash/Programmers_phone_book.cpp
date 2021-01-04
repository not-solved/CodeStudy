#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    for (int i = 0; i < phone_book.size(); i++) {
        string temp = phone_book[i];
        for (int j = 0; j < phone_book.size(); j++) {
            if (j == i || temp.length() > phone_book[j].length())
                continue;
            string comp = phone_book[j].substr(0, temp.length());
            if (temp == comp)
                return false;
        }
    }
    return true;
}