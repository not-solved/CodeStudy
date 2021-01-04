#include <string>
#include <vector>
using namespace std;

string get_pattern(string m) {
    string pattern = "";
    for (int i = 0; i < m.length(); i++) {
        if (m[i] == '#')
            pattern.back() += 32;
        else
            pattern = pattern + m[i];
    }
    return pattern;
}

int playtime(string info) {
    int start = stoi(info.substr(6, 2)) * 60 + stoi(info.substr(9, 2));
    int end = stoi(info.substr(0, 2)) * 60 + stoi(info.substr(3, 2));
    return start - end;
}

string solution(string m, vector<string> musicinfos) {
    int hour, minute, length, max_playtime = 0, idx;
    string answer = "(None)", name, music, temp, pattern = get_pattern(m);
    for (int i = 0; i < musicinfos.size(); i++) {
        int idx = 0, length = playtime(musicinfos[i]);
        while (musicinfos[i][12 + idx] != ',') {
            idx++;
        }
        name = musicinfos[i].substr(12, idx);
        music = get_pattern(musicinfos[i].substr(13 + idx, musicinfos[i].length()));

        temp = "";
        for (int i = 0; i < length; i++)
            temp = temp + music[i % music.length()];

        idx = 0;
        while (idx + pattern.length() <= length) {
            if (pattern == temp.substr(idx++, pattern.length())) {
                if (length > max_playtime) {
                    answer = name;
                    max_playtime = length;
                }
                break;
            }
        }
    }
    return answer;
}