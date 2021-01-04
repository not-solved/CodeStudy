#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	do {
		string input;
		getline(cin, input);
		if (input[0] == '.')
			break;

		int i = 0;
		bool balanced = true;
		stack<char> b;

		while (input[i] != '.') {
			if (input[i] == '(' || input[i] == '[')
				b.push(input[i]);
			else if (input[i] == ')') {
				if (b.empty() || b.top() == '[') {
					balanced = false;
					break;
				}
				else if (b.top() == '(')
					b.pop();
			}
			else if (input[i] == ']') {
				if (b.empty() || b.top() == '(') {
					balanced = false;
					break;
				}
				else if (b.top() == '[')
					b.pop();
			}
			i++;
		}
		if (balanced && b.empty())
			cout << "yes";
		else
			cout << "no";
		cout << "\n";
	} while (true);
	return 0;
}