#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int l, u, x;
		cin >> l >> u >> x;
		int more = 0;
		if (x < l)
			more = l - x;
		else if (x > u)
			more = -1;
		else if (x >= l && x <= u)
			more = 0;

		cout << "#" << a << " " << more << "\n";
	}
	return 0;
}