#include <iostream>
using namespace std;

bool map[15][15];
bool col[15];
bool dig1[40];
bool dig2[40];
int N;

bool check(int r, int c) {
	if (col[c])
		return false;
	if (dig1[r + c])
		return false;
	if (dig2[r - c + N])
		return false;
	return true;
}

int calc(int r) {
	if (r == N)
		return 1;
	int cnt = 0;
	for (int c = 0; c < N; c++) {
		if (check(r, c)) {
			dig1[r + c] = true;
			dig2[r - c + N] = true;
			col[c] = true;

			cnt += calc(r + 1);
			dig1[r + c] = false;
			dig2[r - c + N] = false;
			col[c] = false;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cout << calc(0);
	return 0;
}