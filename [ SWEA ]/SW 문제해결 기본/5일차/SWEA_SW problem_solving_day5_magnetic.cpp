#include <iostream>
using namespace std;

int table[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int a = 1; a <= 10; a++) {
		int size;
		cin >> size;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cin >> table[i][j];
				if (table[i][j] == 2 && i == 0)
					table[i][j] = 0;
				if (table[i][j] == 1 && i == size - 1)
					table[i][j] = 0;
			}
		}
		int count = 0;
		for (int j = 0; j < size; j++) {
			for (int i = 0; i < size; i++) {
				if (table[i][j] == 1) {
					table[i][j] = 0;
					while (table[i][j] != 2 && i < size - 1) {
						if (table[i + 1][j] == 2) {
							count++;
							table[i + 1][j] = 0;
							break;
						}
						table[i][j] = 0;
						i++;
					}
				}
			}
		}
		cout << "#" << a << " " << count << "\n";
	}
	return 0;
}