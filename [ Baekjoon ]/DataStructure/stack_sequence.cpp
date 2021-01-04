#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string result;
	stack<int> A;
	int n;
	cin >> n;
	int input;
	int temp = 0;
	while (n--) {
		cin >> input;
		if (input > temp) {
			while (input > temp) {
				A.push(++temp);
				result += '+';
			}
			A.pop();
			result += '-';
		}
		else {
			if (input == A.top()) {
				A.pop();
				result += '-';
			}
			else {
				cout << "NO\n";
				return 0;
			}
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}