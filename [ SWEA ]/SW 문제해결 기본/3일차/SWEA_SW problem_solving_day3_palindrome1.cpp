#include <iostream>
using namespace std;

char map[8][8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop = 10;
	for (int a = 1; a <= loop; a++) {
		int length;
		cin >> length;

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> map[i][j];

		int count = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8 - length + 1; j++) {
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
					count++;
			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8 - length + 1; j++) {
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
					count++;
			}
		}

		cout << "#" << a << " " << count << "\n";
	}
	return 0;
}