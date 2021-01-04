#include <vector>
#include <iostream>
using namespace std;

bool is_Prime(int target) {
    if (target < 2)
        return false;
    for (int i = 2; i * i <= target; i++) {
        if (target % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int Primes = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (is_Prime(nums[i] + nums[j] + nums[k]))
                    Primes++;
            }
        }
    }
    return Primes;
}