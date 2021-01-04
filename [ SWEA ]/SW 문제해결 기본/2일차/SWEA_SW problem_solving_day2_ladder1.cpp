#include <iostream>
using namespace std;

int ladder[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int a = 1; a <= 10; a++) {
		int test;
		cin >> test;

		int index;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> ladder[i][j];

				if (ladder[i][j] == 2)
					index = j;
			}
		}

		for (int i = 99; i > 0; i--) {
			if (ladder[i][index - 1] == 1 && index > 0) {
				while (ladder[i][index - 1] == 1 && index >= 0) {
					index--;
				}
				continue;
			}
			if (ladder[i][index + 1] == 1 && index < 99) {
				while (ladder[i][index + 1] == 1 && index <= 99) {
					index++;
				}
				continue;
			}
		}

		cout << "#" << test << " " << index << "\n";
	}
	return 0;
}