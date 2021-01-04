#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> IPv6;
int group[2] = { 0, };

void split(string ip) {
    int i = 0;
    int index = 0;
    while (i < ip.length()) {
        if (ip[i] == ':') {
            i++;
            if (ip[i] == ':') {     // 생략 그룹 만났을 때
                index++;
                i++;
            }
        }
        else {
            int counter = 0;
            while (i + counter < ip.length() && ip[i + counter] != ':') {
                counter++;
            }
            string temp = "";
            for (int i = 0; i < 4 - counter; i++)
                temp += "0";
            temp += ip.substr(i, counter);
            IPv6.push_back(temp);
            group[index]++;
            i += counter;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string short_IP;
    cin >> short_IP;
    split(short_IP);

    int middle = 8 - group[0] - group[1];
    int total = 8;
    string result = "";

    for (int i = 0; i < group[0]; i++) {
        result += IPv6[i];
        total--;
        if (total > 0)
            result += ":";
    }
    for (int i = 0; i < middle; i++) {
        result += "0000";
        total--;
        if (total > 0)
            result += ":";
    }
    for (int i = 0; i < group[1]; i++) {
        result += IPv6[group[0] + i];
        total--;
        if (total > 0)
            result += ":";
    }

    cout << result << endl;
    return 0;
}