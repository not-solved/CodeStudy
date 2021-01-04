#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int planet[10];

string translate[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string test;
		int size;
		cin >> test >> size;

		string input;
		memset(planet, 0, sizeof(planet));
		for (int i = 0; i < size; i++) {
			cin >> input;
			for (int j = 0; j < 10; j++) {
				if (!input.compare(translate[j])) {
					planet[j]++;
					break;
				}
			}
		}
		cout << test << "\n";
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < planet[i]; j++)
				cout << translate[i] << " ";
		cout << "\n";
	}
	return 0;
}