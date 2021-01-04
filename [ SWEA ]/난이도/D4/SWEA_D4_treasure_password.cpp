#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int numbers;
		cin >> numbers;
		long result, input, max = 0, min = 1000000;
		for (int i = 0; i < numbers; i++) {
			cin >> input;
			if (max < input)
				max = input;
			if (min > input)
				min = input;
		}

		if (numbers == 1)
			result = input * input;
		else {
			result = max * min;
		}
		cout << "#" << a << " " << result << "\n";
	}
	return 0;
}