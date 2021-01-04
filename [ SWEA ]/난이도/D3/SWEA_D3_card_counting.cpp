#include <iostream>
#include <cstring>
using namespace std;

int deck[4][14];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string input;
		cin >> input;
		int size[4] = { 0, };
		memset(deck, 0, sizeof(deck));
		int index = 0, shape;
		bool overlap = false;
		for (int i = 0; i < input.size(); i += 3) {
			index = (input[i + 1] - 48) * 10 + (input[i + 2] - 48);
			switch (input[i]) {
			case 'S':
				shape = 0;
				break;
			case 'D':
				shape = 1;
				break;
			case 'H':
				shape = 2;
				break;
			case 'C':
				shape = 3;
				break;
			}
			if (deck[shape][index] == 1) {
				overlap = true;
				break;
			}
			else {
				deck[shape][index] = 1;
				size[shape]++;
			}
		}
		cout << '#' << a << ' ';
		if (overlap)
			cout << "ERROR\n";
		else {
			for (int i = 0; i < 4; i++)
				cout << 13 - size[i] << ' ';
			cout << '\n';
		}
	}
	return 0;
}