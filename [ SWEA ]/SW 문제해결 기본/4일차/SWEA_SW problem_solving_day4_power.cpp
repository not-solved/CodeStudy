#include <iostream>
using namespace std;

int power(int i, int f) {
	if (f == 1)
		return i;
	else if (f % 2 != 0) {
		return power(i, f / 2) * power(i, f / 2) * i;
	}
	else {
		return power(i, f / 2) * power(i, f / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop = 10;

	for (int a = 1; a <= loop; a++) {
		int test;
		cin >> test;

		int integer, factor;
		cin >> integer >> factor;
		int result = power(integer, factor);

		cout << "#" << test << " " << result << "\n";
	}
	return 0;
}