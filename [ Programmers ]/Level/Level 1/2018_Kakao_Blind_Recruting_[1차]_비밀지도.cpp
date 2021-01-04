#include <string>
#include <vector>

using namespace std;
string translate(int dec, int length) {
    string result = "";
    for (int i = 0; i < length; i++) {
        if (dec % 2 == 1)
            result += '#';
        else
            result += ' ';
        dec /= 2;
    }
    return result;
}

string reverse(string input, int size) {
    string result = "";
    for (int i = size - 1; i >= 0; i--)
        result += input[i];
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < arr1.size(); i++) {
        int temp = arr1[i] | arr2[i];
        string Code = translate(temp, n);
        answer.push_back(reverse(Code, n));
    }
    return answer;
}