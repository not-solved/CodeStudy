#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0, size = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> bucket;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0 || bucket.back() != nums[i])
            bucket.push_back(nums[i]);
        if (bucket.size() >= size / 2)
            return bucket.size();
    }
    return bucket.size();
}