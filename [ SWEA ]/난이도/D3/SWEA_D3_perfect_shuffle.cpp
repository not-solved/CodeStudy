#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int decks;
		cin >> decks;
		vector<string> card1(decks / 2 + 1);
		vector<string> card2(decks / 2 + 1);

		for (int i = 0; i < decks / 2; i++) {
			cin >> card1[i];
		}
		if (decks % 2 == 1)
			cin >> card1[decks / 2];
		for (int i = 0; i < decks / 2; i++) {
			cin >> card2[i];
		}

		cout << '#' << a << ' ';
		for (int i = 0; i < decks / 2; i++) {
			cout << card1[i] << ' ' << card2[i] << ' ';
		}
		if (decks % 2 == 1)
			cout << card1[decks / 2];
		cout << '\n';
	}
	return 0;
}