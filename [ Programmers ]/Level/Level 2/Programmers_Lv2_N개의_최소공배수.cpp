#include <string>
#include <vector>

using namespace std;
int get_GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return get_GCD(b, a % b);
}
int get_LCD(int a, int b, int gcd) {
    return (a * b) / gcd;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        answer = get_LCD(answer, arr[i], get_GCD(answer, arr[i]));
    }
    return answer;
}