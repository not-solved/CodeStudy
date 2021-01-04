#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int commands;
		cin >> commands;
		vector<int> history;
		int com, deg, answer = 0, v = 0;
		for (int b = 0; b < commands; b++) {
			cin >> com;
			if (com == 0)
				answer += v;
			else {
				cin >> deg;
				if (com == 1) {
					v += deg;
					answer += v;
				}
				else {
					v -= deg;
					if (v < 0)
						v = 0;
					answer += v;
				}
			}
		}
		cout << "#" << a << " " << answer << "\n";
	}
	return 0;
}