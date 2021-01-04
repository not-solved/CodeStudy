#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int city, dist;
		cin >> city >> dist;
		vector<int> kingdom(city);
		for (int i = 0; i < city; i++)
			cin >> kingdom[i];

		int count = 0;
		int index = 0;
		if (!kingdom[0]) {
			kingdom[0] = 1;
			count++;
			index++;
		}
		while (index < city) {
			bool find = false;
			for (int i = 0; i < dist; i++) {
				if (kingdom[index + i] == 1) {
					index += i + 1;
					find = true;
					break;
				}
			}
			if (!find) {
				if (!kingdom[index + (dist - 1)]) {
					kingdom[index + (dist - 1)] = 1;
					count++;
					index += dist - 1;
				}
			}

		}
		cout << '#' << a << ' ' << count << '\n';
	}
	return 0;
}