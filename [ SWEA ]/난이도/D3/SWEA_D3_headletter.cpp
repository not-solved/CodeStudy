#include <iostream>
#include <string>
using namespace std;

int main() {

	int loop;
	cin >> loop;
	cin.ignore();
	for (int a = 1; a <= loop; a++) {
		string input, result;
		getline(cin, input);
		char front = input[0] - 32;
		result += front;
		for (int i = 1; i < input.size(); i++) {
			if (input[i - 1] == ' ') {
				front = input[i] - 32;
				result += front;
			}
		}
		cout << "#" << a << " " << result << "\n";
	}
	return 0;
}