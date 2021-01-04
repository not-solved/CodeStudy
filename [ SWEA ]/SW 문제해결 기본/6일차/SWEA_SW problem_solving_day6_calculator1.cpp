#include <iostream>
using namespace std;

char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop = 10;

	for (int a = 1; a <= loop; a++) {
		int size;
		cin >> size;
		char input;
		int sum = 0;
		for (int i = 0; i < size; i++) {
			cin >> input;
			for (int j = 0; j < 10; j++) {
				if (input == numbers[j]) {
					sum += j;
					break;
				}
			}
		}
		cout << "#" << a << " " << sum << "\n";
	}
	return 0;
}