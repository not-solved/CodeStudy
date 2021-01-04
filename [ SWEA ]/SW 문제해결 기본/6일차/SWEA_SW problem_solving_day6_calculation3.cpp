#include <iostream>
#define MAX 150
#define MAX_STACK	100000
using namespace std;

char postfix[MAX];
char infix[MAX];
int index;
int S;

class STK {
public:
	void STK_init() {
		index_c = -1;
		index_i = -1;
	}
	bool isEmpty_char() {
		return (index_c == -1 ? true : false);
	}
	bool isEmpty_int() {
		return (index_i == -1 ? true : false);
	}
	char top_char() {
		return (isEmpty_char() ? '\0' : Stack_c[index_c]);
	}
	int top_int() {
		return (isEmpty_int() ? '\0' : Stack_i[index_i]);
	}
	void push_char(char in) {
		index_c++;
		Stack_c[index_c] = in;
	}
	void push_int(int in) {
		index_i++;
		Stack_i[index_i] = in;
	}
	void pop_char() {
		if (!isEmpty_char())
			index_c--;
	}
	void pop_int() {
		if (!isEmpty_int())
			index_i--;
	}
private:
	char Stack_c[MAX_STACK];
	int Stack_i[MAX_STACK];
	int index_c;
	int index_i;
};

STK op;

void to_postfix() {
	index = 0;
	for (int i = 0; i < S; i++) {
		if (infix[i] == '(')
			op.push_char(infix[i]);
		else if (infix[i] == ')') {
			while (op.top_char() != '(') {
				postfix[index] = op.top_char();
				index++;
				op.pop_char();
			}
			op.pop_char();
		}
		else if (infix[i] == '+') {
			while (!op.isEmpty_char() && (op.top_char() == '+' || op.top_char() == '*')) {
				postfix[index] = op.top_char();
				index++;
				op.pop_char();
			}
			op.push_char(infix[i]);
		}
		else if (infix[i] == '*') {
			while (!op.isEmpty_char() && op.top_char() == '*') {
				postfix[index] = op.top_char();
				index++;
				op.pop_char();
			}
			op.push_char(infix[i]);
		}
		else {
			postfix[index] = infix[i];
			index++;
		}
	}
	while (!op.isEmpty_char()) {
		postfix[index] = op.top_char();
		op.pop_char();
		index++;
	}
}
int solve() {
	int result = 0;
	for (int i = 0; i < index; i++) {
		if (postfix[i] == '*') {
			result = op.top_int();
			op.pop_int();
			result *= op.top_int();
			op.pop_int();
			op.push_int(result);
		}
		else if (postfix[i] == '+') {
			result = op.top_int();
			op.pop_int();
			result += op.top_int();
			op.pop_int();
			op.push_int(result);
		}
		else
			op.push_int(postfix[i] - '0');
	}
	result = op.top_int();
	op.pop_int();
	return result;
}
void init() {
	op.STK_init();
	cin >> S;
	for (int i = 0; i < S; i++) {
		infix[i] = '\0';
		postfix[i] = '\0';
	}
	cin >> infix;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int a = 1; a <= 10; a++) {
		init();
		to_postfix();
		cout << "#" << a << " " << solve() << "\n";
	}
	return 0;
}