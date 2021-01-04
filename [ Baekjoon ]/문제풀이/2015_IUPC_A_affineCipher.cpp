#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int loop;
	cin >> loop;
	while (loop--) {
		int a, b, pw;
		cin >> a >> b;
		string input;
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			pw = (a * (input[i] - 65) + b) % 26;
			input[i] = pw + 65;
		}
		cout << input << '\n';
	}
	return 0;
}