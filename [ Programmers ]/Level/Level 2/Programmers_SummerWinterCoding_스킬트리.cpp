#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

bool check_tree(string skill, string tree) {
    int tree_index[26];
    memset(tree_index, -1, sizeof(tree_index));
    // 스킬트리 안의 스킬들 
    for (int i = 0; i < tree.length(); i++) {
        tree_index[tree[i] - 65] = i + 1;
    }
    /*      확인
    cout << "Current : " << tree << '\t';
    for(int i = 0; i < skill.length(); i++)
        cout << tree_index[skill[i] - 65] << ' ';
    cout << endl;
    */
    int prev = tree_index[skill[0] - 65];
    bool blank = false;
    for (int i = 1; i < skill.length(); i++) {
        if (tree_index[skill[i] - 65] != -1) {
            if (prev == -1 || blank)
                return false;
            else if (prev > tree_index[skill[i] - 65])
                return false;
            else
                prev = tree_index[skill[i] - 65];
        }
        else if (prev != -1)
            blank = true;
    }
    return true;
}

string get_skill(string skill, string skill_tree) { // 스킬트리에 있는 스킬만 추출
    bool in_tree[26] = { 0, };
    for (int i = 0; i < skill.length(); i++)
        in_tree[skill[i] - 65] = true;
    string result = "";
    for (int i = 0; i < skill_tree.length(); i++)
        if (in_tree[skill_tree[i] - 65])
            result = result + skill_tree[i];
    return result;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        string temp = get_skill(skill, skill_trees[i]);
        if (temp.length() == 0 || check_tree(skill, temp))
            answer++;
    }
    return answer;
}