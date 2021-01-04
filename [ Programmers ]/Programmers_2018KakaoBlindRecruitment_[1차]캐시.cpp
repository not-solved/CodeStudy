#include <string>
#include <vector>

using namespace std;
string to_Lower(string input) {
    string result = input;
    for (int i = 0; i < input.length(); i++) {
        if (result[i] >= 'A' && result[i] <= 'Z')
            result[i] += 32;
    }
    return result;
}
int Search(vector<string> cache, string t) {
    for (int i = 0; i < cache.size(); i++)
        if (cache[i] == t)
            return i;
    return -1;
}
int find_Least(vector<int> time) {
    int result = 1000000;
    int idx = 0;
    for (int i = 0; i < time.size(); i++) {
        if (result > time[i]) {
            result = time[i];
            idx = i;
        }
    }
    return idx;
}

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0)
        return cities.size() * 5;

    int answer = 0, idx = 0;
    vector<string> Cache(cacheSize);
    vector<int> Time(cacheSize);

    for (int i = 0; i < cities.size(); i++) {
        if (!idx) {
            answer += 5;
            Cache[idx] = to_Lower(cities[i]);
            Time[idx++] = i;
        }
        else {
            int find = Search(Cache, to_Lower(cities[i]));
            if (find >= 0) {
                answer++;
                Time[find] = i;
            }
            else {
                answer += 5;
                if (idx < cacheSize) {
                    Cache[idx] = to_Lower(cities[i]);
                    Time[idx++] = i;
                }
                else {
                    int L = find_Least(Time);
                    Cache[L] = to_Lower(cities[i]);
                    Time[L] = i;
                }
            }
        }
    }
    return answer;
}