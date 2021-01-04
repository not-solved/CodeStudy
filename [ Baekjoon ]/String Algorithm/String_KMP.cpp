#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void KMP(string input, string pattern) {
	int t = input.size();
	int p = pattern.size();

	vector<int> F(p, 0);

	int begin = 1;
	int matched = 0;

	while (begin + matched < p) {
		if (pattern[begin + matched] == pattern[matched]) {
			matched++;
			F[begin + matched - 1] = matched;
		}
		else if (matched > 0) {
			begin += (matched - F[matched - 1]);
			matched = F[matched - 1];
		}
		else
			begin++;
	}

	begin = 0;
	matched = 0;
	vector<int> indexes;

	while (begin <= t - p) {
		if (input[begin + matched] == pattern[matched]) {
			matched++;
			if (matched == p)
				indexes.push_back(begin);
		}
		else if (matched > 0) {
			begin += (matched - F[matched - 1]);
			matched = F[matched - 1];
		}
		else
			begin++;
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

	cout << "\nfind with KMP\n";
	KMP(input, pattern);

	return 0;
}