#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> list;
int using_index[7] = { 0, };

void make_list(int length, string nums, int temp, string made_number) {
    if (temp >= length) {
        int N = stoi(made_number);
        if (N < 2)
            return;
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == N)
                return;
        }
        list.push_back(N);
        return;
    }
    for (int i = 0; i < nums.length(); i++) {
        if (using_index[i] == 0) {
            made_number += nums[i];
            using_index[i] = 1;
            make_list(length, nums, temp + 1, made_number);
            made_number.pop_back();
            using_index[i] = 0;
        }
    }
}

int solution(string numbers) {
    int answer = 0;

    for (int i = 1; i <= numbers.length(); i++) {
        make_list(i, numbers, 0, "");
    }
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == 2 || list[i] == 3) {
            answer++;
            continue;
        }
        int SQRT = sqrt(list[i]);
        bool isprime = true;
        for (int j = 2; j < SQRT + 1; j++) {
            if (list[i] % j == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime)
            answer++;
    }
    return answer;
}