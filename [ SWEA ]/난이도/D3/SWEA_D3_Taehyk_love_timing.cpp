#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int D, H, M;
		cin >> D >> H >> M;
		int effort = (D * 1440 + H * 60 + M) - (11 * (1440 + 60 + 1));
		if (effort < 0)
			effort = -1;
		cout << '#' << a << ' ' << effort << '\n';
	}
	return 0;
}