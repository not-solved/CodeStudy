#include <iostream>
#include <vector>
using namespace std;

vector<int> V[1001];
double operand[1001];
char operation[501];

double calculation(int index, int size) {
	if (index <= size / 2) {
		if (operation[index] == '+')
			return calculation(V[index][0], size) + calculation(V[index][1], size);
		else if (operation[index] == '-')
			return calculation(V[index][0], size) - calculation(V[index][1], size);
		else if (operation[index] == '*')
			return calculation(V[index][0], size) * calculation(V[index][1], size);
		else if (operation[index] == '/') {
			double result2 = calculation(V[index][1], size);
			if (result2 != 0)
				return calculation(V[index][0], size) / result2;
		}
	}
	else
		return operand[index];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int test = 1; test <= 10; test++) {
		int size;
		cin >> size;
		int index = 1, tar1, tar2;
		for (int i = 0; i < size; i++) {
			if (i < size / 2) {
				cin >> index;
				cin >> operation[index] >> tar1 >> tar2;
				V[index].push_back(tar1);
				V[index].push_back(tar2);
			}
			else {
				cin >> index;
				cin >> operand[index];
			}
		}
		long long result = calculation(1, size);
		cout << "#" << test << " " << result << "\n";
	}
	return 0;
}