#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int temp = x;
    int check = 0;
    while (x > 0) {
        check += x % 10;
        x /= 10;
    }
    if (temp % check == 0)
        return true;
    else
        return false;
}