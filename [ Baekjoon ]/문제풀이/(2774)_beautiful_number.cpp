#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int numbers;
	cin >> numbers;
	while (numbers--) {
		int count = 0;
		vector<int> beautiful(10, 0);
		string input;
		cin >> input;
		for (int i = 0; i < input.length(); i++) {
			if (beautiful[input[i] - 48] == 0) {
				beautiful[input[i] - 48] = 1;
				count++;
			}
		}
		cout << count << '\n';
	}
	return 0;
}