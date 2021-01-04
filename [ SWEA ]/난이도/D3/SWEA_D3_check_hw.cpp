#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int students, submits, input;
		cin >> students >> submits;
		vector<bool> V(students + 1, false);
		for (int i = 0; i < submits; i++) {
			cin >> input;
			V[input] = true;
		}
		cout << '#' << a << ' ';
		for (int i = 0; i < students; i++) {
			if (!V[i + 1])
				cout << i + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}