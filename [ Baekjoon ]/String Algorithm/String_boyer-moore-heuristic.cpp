#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

void BMH(string input, string pattern) {
	int LastOccurance[128] = { -1, };
	int t = input.size();
	int p = pattern.size();
	for (int i = 0; i < p; i++)
		LastOccurance[pattern[i]] = i;

	int last = p - 1;
	int matched = p - 1;
	vector<int> indexes;

	while (last < t) {
		if (input[last] == pattern[matched]) {
			if (matched == 0) {
				indexes.push_back(last);
				matched = p - 1;
				last += p;
				cout << endl;
			}
			else {
				last--;
				matched--;
			}
		}
		else {
			int l = LastOccurance[input[last]] + 1;
			last = last + p - (matched < l ? matched : l);
			matched = p - 1;
		}
	}
	if (indexes.size() == 0)
		cout << "Error - no such pattern\n";
	else {
		for (int i = 0; i < indexes.size(); i++) {
			cout << "- find in " << indexes[i] << "\n";
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input, pattern;
	cout << "문자열 입력 : ";
	getline(cin, input);
	cout << "부분 문자열 : ";
	getline(cin, pattern);

	cout << "\nfind with Boyer-Moore Heuristic\n";
	BMH(input, pattern);

	return 0;
}