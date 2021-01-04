#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string input;
		cin >> input;
		cout << "#" << a << " ";
		for (int i = 0; i < input.size(); i++) {
			if (input[i] != 'a' && input[i] != 'e' && input[i] != 'i' &&
				input[i] != 'o' && input[i] != 'u')
				cout << input[i];
		}
		cout << "\n";
	}
	return 0;
}