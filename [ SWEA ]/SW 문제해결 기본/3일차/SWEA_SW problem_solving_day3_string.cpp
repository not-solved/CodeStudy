#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int KMP(string input, string pattern) {
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
	queue<int> indexes;

	while (begin <= t - p) {
		if (input[begin + matched] == pattern[matched]) {
			matched++;
			if (matched == p)
				indexes.push(begin);
		}
		else if (matched > 0) {
			begin += (matched - F[matched - 1]);
			matched = F[matched - 1];
		}
		else
			begin++;
	}
	return indexes.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop = 10;
	while (loop--) {
		int test;
		cin >> test;
		string T, pattern;
		cin >> pattern >> T;
		int count = KMP(T, pattern);

		cout << "#" << test << " " << count << "\n";
	}
	return 0;
}