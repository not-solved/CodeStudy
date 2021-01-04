#include <iostream>
#include <stack>
using namespace std;

char postfix[150];
char infix[150];

void to_postfix(int size) {
	int index = 0;
	stack<char> op1;
	stack<int> op2;
	for (int i = 0; i < size; i++) {
		if (infix[i] == '(')
			op1.push(infix[i]);
		else if (infix[i] == ')') {
			while (op1.top() != '(') {
				postfix[index] = op1.top();
				op1.pop();
				index++;
			}
			op1.pop();
		}
		else if (infix[i] == '*') {
			while (!op1.empty() && op1.top() == '*') {
				postfix[index] = op1.top();
				op1.pop();
				index++;
			}
			op1.push(infix[i]);
		}
		else if (infix[i] == '+') {
			while (!op1.empty() && (op1.top() == '+' || op1.top() == '*')) {
				postfix[index] = op1.top();
				op1.pop();
				index++;
			}
			op1.push(infix[i]);
		}
		else {
			postfix[index] = infix[i];
			index++;
		}
	}
	while (!op1.empty()) {
		postfix[index] = op1.top();
		op1.pop();
		index++;
	}
}
long solve(int size) {
	long result = 0;
	stack<char> op1;
	stack<int> op2;
	for (int i = 0; i < size; i++) {
		if (postfix[i] == '*') {
			result = op2.top();
			op2.pop();
			result *= op2.top();
			op2.pop();
			op2.push(result);
		}
		else if (postfix[i] == '+') {
			result = op2.top();
			op2.pop();
			result += op2.top();
			op2.pop();
			op2.push(result);
		}
		else
			op2.push(postfix[i] - '0');
	}
	result = op2.top();
	op2.pop();
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int a = 1; a <= 10; a++) {
		int size;
		cin >> size;
		cin >> infix;
		to_postfix(size);
		cout << "#" << a << " " << solve(size) << "\n";
	}
	return 0;
}