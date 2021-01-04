#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int ladder[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int a = 1; a <= 10; a++) {
		int test;
		cin >> test;

		for (int i = 0; i < 100; i++) {
			ladder[100][i] = 0;
			ladder[i][100] = 0;
		}
		ladder[100][100] = 0;

		int extra = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> ladder[i][j];
				ladder[i][100] += ladder[i][j];
				ladder[100][j] += ladder[i][j];
			}
			ladder[100][100] += ladder[i][i];
			extra += ladder[i][99 - i];
		}
		int max = (extra > ladder[100][100] ? extra : ladder[100][100]);
		for (int i = 0; i < 100; i++) {
			if (max < ladder[i][100])
				max = ladder[i][100];
			if (max < ladder[100][i])
				max = ladder[100][i];
		}

		cout << "#" << test << " " << max << "\n";
	}
	return 0;
}