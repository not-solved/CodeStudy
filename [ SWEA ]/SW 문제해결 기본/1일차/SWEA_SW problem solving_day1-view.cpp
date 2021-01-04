#include <iostream>
using namespace std;

int building[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int test_case = 1; test_case <= 10; test_case++) {
		int num;
		cin >> num;

		for (int i = 0; i < num; i++)
			cin >> building[i];
		building[num - 2] = 0;
		building[num - 1] = 0;
		int count = 0;
		for (int i = 2; i < num - 2; i++) {
			int gap = 1000;
			if (i == num - 3) {

			}
			if (building[i] - building[i - 1] > 0 && building[i] - building[i + 1] > 0
				&& building[i] - building[i - 2] > 0 && building[i] - building[i + 2] > 0) {
				if (gap > building[i] - building[i - 1])
					gap = building[i] - building[i - 1];
				if (gap > building[i] - building[i + 1])
					gap = building[i] - building[i + 1];
				if (gap > building[i] - building[i - 2])
					gap = building[i] - building[i - 2];
				if (gap > building[i] - building[i + 2])
					gap = building[i] - building[i + 2];

				count += gap;
				i += 2;
			}
		}
		cout << "#" << test_case << " " << count << "\n";
	}
	return 0;
}