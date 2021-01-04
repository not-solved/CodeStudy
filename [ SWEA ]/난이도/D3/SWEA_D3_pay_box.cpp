#include <iostream>
#include <iomanip>
using namespace std;

int tree[1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int n;
		cin >> n;
		double average = 0;
		double p, x;
		for (int i = 0; i < n; i++) {
			cin >> p >> x;
			average += (p * x);
		}
		cout << '#' << a << ' ';
		cout << fixed;
		cout.precision(6);
		cout << average << '\n';
	}
	return 0;
}