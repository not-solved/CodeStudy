#include <iostream>
#include <string>
using namespace std;

void BruteForce(string input, string pattern) {
	bool find = true;
	int count = 0;
	for (int i = 0; i < input.size() - pattern.size() + 1; i++) {
		find = true;
		for (int j = 0; j < pattern.size(); j++) {
			if (pattern[j] != input[i + j]) {
				find = false;
				break;
			}
		}
		if (find == true) {
			count++;
			cout << "- find in " << i << "\n";
		}
	}
	if (count == 0)
		cout << "Error : no such pattern\n";
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

	cout << "\nFind with Brute-Force\n";
	BruteForce(input, pattern);

	return 0;
}