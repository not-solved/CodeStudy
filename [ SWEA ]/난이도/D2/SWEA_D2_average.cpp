#include <iostream>
#include <math.h>
using namespace std;

int sudoku[10][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	double average, input, max, min;
	for (int a = 1; a <= n; a++) {
		max = 0;
		min = 10000;
		average = 0;
		for (int i = 0; i < 10; i++) {
			cin >> input;
			average += input;
			if (input > max)
				max = input;
			if (input < min)
				min = input;
		}
		average = (average - max - min) / 8;
		cout << "#" << a << " " << floor(average + 0.5) << "\n";
	}
	return 0;
}