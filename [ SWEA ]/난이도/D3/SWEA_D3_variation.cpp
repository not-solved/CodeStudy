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
		bool check[10] = { 0, };
		int count = 0;
		int index;
		for (int i = 0; i < input.size(); i++) {
			index = input[i] - '0';
			if (check[index] == false) {
				count++;
				check[index] = true;
			}
		}
		cout << '#' << a << ' ' << count << '\n';
	}
	return 0;
}