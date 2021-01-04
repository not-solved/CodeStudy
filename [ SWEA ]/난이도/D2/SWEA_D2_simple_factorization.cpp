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
		long input;
		cin >> input;
		long integers[5] = { 2, 3, 5, 7, 11 };
		int count[5] = { 0, };
		int index = 0;
		for (int i = 0; i < 5; i++) {
			while (true) {
				if (input % integers[i] != 0)
					break;
				input /= integers[i];
				count[i]++;
			}
		}
		cout << "#" << a << " ";
		for (int i = 0; i < 5; i++) {
			cout << count[i];
			if (i < 5)
				cout << " ";
			else
				cout << "\n";
		}
	}
	return 0;
}