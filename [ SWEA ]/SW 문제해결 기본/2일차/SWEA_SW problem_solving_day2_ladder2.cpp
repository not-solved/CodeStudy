#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ladder[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int a = 1; a <= 10; a++) {
		int test;
		cin >> test;

		queue<int> start;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> ladder[i][j];
				if (i == 99 && ladder[i][j] == 1)
					start.push(j);
			}
		}

		int shortest = 10000;
		int termination = 0;
		while (!start.empty()) {
			int index = start.front();
			int move = 0;
			for (int i = 99; i >= 0; i--) {
				if (ladder[i][index - 1] == 1 && index > 0) {
					while (ladder[i][index - 1] == 1 && index > 0) {
						index--;
						move++;
					}
					move++;
					continue;
				}
				if (ladder[i][index + 1] == 1 && index < 99) {
					while (ladder[i][index + 1] == 1 && index < 99) {
						index++;
						move++;
					}
					move++;
					continue;
				}
			}
			start.pop();
			if (shortest >= move) {
				shortest = move;
				termination = index;
			}
		}

		cout << "#" << test << " " << termination << "\n";
	}
	return 0;
}