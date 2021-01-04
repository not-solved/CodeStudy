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
		vector<int> V(8, 0);
		int price[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
		int input;
		cin >> input;
		int index = 0;
		while (input > 9) {
			if (input >= price[index]) {
				int r = input / price[index];
				input -= r * price[index];
				V[index] += r;
			}
			index++;
		}

		cout << "#" << a << "\n";
		for (int i = 0; i < 8; i++)
			cout << V[i] << " ";
		cout << "\n";
	}
	return 0;
}