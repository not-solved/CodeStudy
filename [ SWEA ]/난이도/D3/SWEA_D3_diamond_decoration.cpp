#include <iostream>
using namespace std;

char arr1[4] = { '.', '.', '#', '.' };
char arr2[4] = { '.', '#', '.', '#' };
char arr3[4] = { '#', '.', ' ', '.' };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string input;
		cin >> input;
		int index = 0;
		int strindex = 0;
		for (int i = 0; i < input.size() * 4; i++) {
			cout << arr1[index];
			index = (index + 1) % 4;
		}
		cout << ".\n";
		for (int i = 0; i < input.size() * 4; i++) {
			cout << arr2[index];
			index = (index + 1) % 4;
		}
		cout << ".\n";
		for (int i = 0; i < input.size() * 4; i++) {
			if (index == 2)
				cout << input[strindex++];
			else
				cout << arr3[index];
			index = (index + 1) % 4;
		}
		cout << "#\n";
		for (int i = 0; i < input.size() * 4; i++) {
			cout << arr2[index];
			index = (index + 1) % 4;
		}
		cout << ".\n";
		for (int i = 0; i < input.size() * 4; i++) {
			cout << arr1[index];
			index = (index + 1) % 4;
		}
		cout << ".\n";
	}
	return 0;
}