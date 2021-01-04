#include <iostream>
#include <cstring>
using namespace std;

char map[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop = 10;
	while (loop--) {
		int test;
		cin >> test;
		memset(map, 0, sizeof(map));

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> map[i][j];

		int result = 1;
		for (int i = 0; i < 100; i++) {
			for (int length = result; length <= 100; length++) {
				for (int j = 0; j <= 100 - length; j++) {
					int front = j;
					int end = front + length - 1;
					bool find = true;
					while (front < end) {
						if (map[i][front] != map[i][end]) {
							find = false;
							break;
						}
						front++;
						end--;
					}
					if (find)
						result = length;
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int length = result; length <= 100; length++) {
				for (int j = 0; j <= 100 - length; j++) {
					int front = j;
					int end = front + length - 1;
					bool find = true;
					while (front < end) {
						if (map[front][i] != map[end][i]) {
							find = false;
							break;
						}
						front++;
						end--;
					}
					if (find)
						result = length;
				}
			}
		}

		cout << "#" << test << " " << result << "\n";
	}
	return 0;
}