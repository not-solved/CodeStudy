#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int horn, beasts, answer;
		cin >> horn >> beasts;
		for (int i = 0; i <= beasts; i++) {
			if (horn == (2 * i + (beasts - i))) {
				answer = i;
				break;
			}
		}
		cout << '#' << a << ' ' << beasts - answer << ' ' << answer << '\n';
	}
	return 0;
}