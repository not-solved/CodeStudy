#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	int good = 0;
	while (loop--) {
		string input;
		cin >> input;
		stack<char> A;
		A.push(input[0]);
		for (int i = 1; i < input.length(); i++) {
			if (A.empty())
				A.push(input[i]);
			else {
				if (A.top() == input[i])
					A.pop();
				else
					A.push(input[i]);
			}
		}
		if (A.empty())
			good++;
	}
	cout << good;

	return 0;
}