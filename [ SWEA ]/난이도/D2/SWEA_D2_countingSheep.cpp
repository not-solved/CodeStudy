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
		int n;
		cin >> n;
		bool check[10] = { 0, };
		int index = 1;
		int check_cnt = 0;
		while (true) {
			int temp = n * index;
			while (temp > 0) {
				if (!check[temp % 10]) {
					check[temp % 10] = true;
					check_cnt++;
				}
				temp /= 10;
				if (check_cnt >= 10)
					break;
			}
			if (check_cnt >= 10)
				break;
			index++;
		}
		cout << "#" << a << " " << n * index << "\n";
	}
	return 0;
}