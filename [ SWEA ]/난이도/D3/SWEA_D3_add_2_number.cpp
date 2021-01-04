#include <iostream>
#include <string>
using namespace std;

string calculate(string in1, string in2, int size1, int size2) {
	int num1, num2, next = 0;
	int ind1 = size1 - 1;
	int ind2 = size2 - 1;
	int size = (size1 > size2) ? size1 - 1 : size2 - 1;
	string result;
	while (size >= 0) {
		num1 = (ind1 >= 0) ? in1[ind1--] - 48 : 0;
		num2 = (ind2 >= 0) ? in2[ind2--] - 48 : 0;

		size--;
		int add = (num1 + num2 + next) % 10;
		result += add + 48;
		next = (num1 + num2 + next > 9) ? 1 : 0;
	}
	if (next == 1)
		result += '1';
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string in1, in2;
		cin >> in1 >> in2;
		string result = calculate(in1, in2, in1.size(), in2.size());
		cout << '#' << a << ' ';
		for (int i = result.size() - 1; i >= 0; i--) {
			cout << result[i];
		}
		cout << '\n';
	}
	return 0;
}