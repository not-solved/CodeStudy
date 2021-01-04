#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int size;
		cin >> size;
		int up = 0, down = 0;
		int box[100];
		cin >> box[0];
		for (int i = 1; i < size; i++) {
			cin >> box[i];
			if (box[i] < box[i - 1]) {
				if (down < box[i - 1] - box[i])
					down = box[i - 1] - box[i];
			}
			else if (box[i] > box[i - 1]) {
				if (up < box[i] - box[i - 1])
					up = box[i] - box[i - 1];
			}
		}
		cout << "#" << a << " " << up << " " << down << "\n";
	}
	return 0;
}