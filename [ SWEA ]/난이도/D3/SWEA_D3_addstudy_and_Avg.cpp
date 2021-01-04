#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int score;
		int avg = 0;
		for (int i = 0; i < 5; i++) {
			cin >> score;
			if (score < 40)
				score = 40;
			avg += score;
		}
		cout << '#' << a << ' ' << avg / 5 << '\n';
	}
	return 0;
}