#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop = 10;
	for (int a = 1; a <= loop; a++) {
		int test;
		cin >> test;

		string input;
		cin >> input;
		stack<char> bracket;
		bool check = true;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '(' || input[i] == '{' || input[i] == '[' || input[i] == '<')
				bracket.push(input[i]);
			else {
				if (bracket.empty()) {
					check = false;
					break;
				}
				else {
					if (input[i] == ')') {
						if (bracket.top() != '(') {
							check = false;
							break;
						}
					}
					else if (input[i] == '}') {
						if (bracket.top() != '{') {
							check = false;
							break;
						}
					}
					else if (input[i] == ']') {
						if (bracket.top() != '[') {
							check = false;
							break;
						}
					}
					else if (input[i] == '>') {
						if (bracket.top() != '<') {
							check = false;
							break;
						}
					}
				}
				bracket.pop();
			}
		}
		if (!bracket.empty())
			check = false;

		cout << "#" << a << " " << check << "\n";
	}
	return 0;
}