#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	cin.ignore();
	for (int a = 1; a <= loop; a++) {
		int input;
		int max = 0;
		int min = 1000000;
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			cin >> input;
			sum = 0;
			while (input > 0) {
				sum += (input % 10);
				input /= 10;
			}
			if (sum > max)
				max = sum;
			if (sum < min)
				min = sum;
		}
		cout << "#" << a << " " << max << " " << min << "\n";
	}
	return 0;
}