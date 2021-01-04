#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int side[3];
		for (int i = 0; i < 3; i++) {
			cin >> side[i];
		}
		int answer;
		if (side[0] == side[1])
			answer = side[2];
		else if (side[0] == side[2])
			answer = side[1];
		else if (side[1] == side[2])
			answer = side[0];
		else if (side[0] == side[1] && side[1] == side[2])
			answer = side[2];
		cout << '#' << a << ' ' << answer << '\n';
	}
	return 0;
}