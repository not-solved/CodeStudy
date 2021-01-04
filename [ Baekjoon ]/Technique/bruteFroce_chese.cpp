#include <iostream>
#include <cstring>
#define MAX	10001
using namespace std;

char map[50][50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> map[i][j];

	int W = 0;
	int B = 0;
	int min = 100;
	for (int i = 0; i < x - 7; i++) {
		for (int j = 0; j < y - 7; j++) {
			W = 0;
			B = 0;
			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					if ((a + b) % 2 == 0 && map[i + a][j + b] != 'W')
						W++;
					else if ((a + b) % 2 == 1 && map[i + a][j + b] != 'B')
						W++;

					if ((a + b) % 2 == 0 && map[i + a][j + b] != 'B')
						B++;
					else if ((a + b) % 2 == 1 && map[i + a][j + b] != 'W')
						B++;
				}
			}
			if (W < B && W < min)
				min = W;
			else if (B <= W && B < min)
				min = B;
		}
	}
	cout << min;
	return 0;
}