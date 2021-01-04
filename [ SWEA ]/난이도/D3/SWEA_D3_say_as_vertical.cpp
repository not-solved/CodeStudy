#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string input[5];
		int max_length = 0;
		for (int i = 0; i < 5; i++) {
			cin >> input[i];
			if (max_length < input[i].length())
				max_length = input[i].length();
		}
		cout << '#' << a << ' ';
		for (int i = 0; i < max_length; i++) {
			for (int j = 0; j < 5; j++) {
				if (i >= input[j].length())
					continue;
				cout << input[j][i];
			}
		}
		cout << '\n';
	}
	return 0;
}