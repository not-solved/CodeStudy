#include <string>
#include <vector>

using namespace std;

vector<string> Split(string target) {
    vector<string> result;
    for (int i = 0; i < target.length(); i++) {
        target[i] = tolower(target[i]);
    }
    for (int i = 0; i < target.length() - 1; i++) {
        if (target[i] >= 'a' && target[i] <= 'z' && target[i + 1] >= 'a' && target[i + 1] <= 'z')
            result.push_back(target.substr(i, 2));
    }
    return result;
}

int calculate(vector<string> small, vector<string> big, string command) {
    int diff = 0;
    vector<bool> check(big.size(), false);
    for (int i = 0; i < small.size(); i++) {
        for (int j = 0; j < big.size(); j++) {
            if (small[i] == big[j] && check[j] == false) {
                diff++;
                check[j] = true;
                break;
            }
        }
    }
    if (command == "Union")
        return big.size() + small.size() - diff;
    else
        return diff;
}

int solution(string str1, string str2) {
    vector<string> S1 = Split(str1);
    vector<string> S2 = Split(str2);
    if (S1.empty() && S2.empty())
        return 65536;

    int U = 0, I = 0;
    if (S1.size() > S2.size()) {
        U = calculate(S2, S1, "Union");
        I = calculate(S2, S1, "Intersect");
    }
    else {
        U = calculate(S1, S2, "Union");
        I = calculate(S1, S2, "Intersect");
    }
    return ((double)I / (double)U) * 65536;
}