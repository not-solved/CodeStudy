#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string input;
		bool check[1000] = { 0, };
		int count = 0;
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			int compare = input[i] + 0;
			if (!check[compare]) {
				check[compare] = true;
				count++;
			}
			else {
				check[compare] = false;
				count--;
			}

		}
		cout << "#" << a << " " << count << "\n";
	}
	return 0;
}