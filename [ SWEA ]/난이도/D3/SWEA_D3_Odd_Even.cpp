#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string input;
		cin >> input;
		string result;
		if (input[input.size() - 1] % 2 == 0)
			result = "Even";
		else
			result = "Odd";

		cout << '#' << a << ' ' << result << '\n';
	}
	return 0;
}