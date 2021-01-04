#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int tree[1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int breadA, breadB, money;
		cin >> breadA >> breadB >> money;
		int count = 0;
		int min = (breadA > breadB) ? breadB : breadA;
		while (money >= min) {
			if (min <= money) {
				money -= min;
				count++;
			}
		}
		cout << '#' << a << ' ' << count << '\n';
	}
	return 0;
}