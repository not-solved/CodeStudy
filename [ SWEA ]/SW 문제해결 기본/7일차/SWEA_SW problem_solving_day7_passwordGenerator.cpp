#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop = 10;
	for (int a = 1; a <= loop; a++) {
		int test;
		cin >> test;

		int input;
		queue<int> password;
		for (int i = 0; i < 8; i++) {
			cin >> input;
			password.push(input);
		}
		int count = 0;
		bool finish = false;
		while (!finish) {
			int temp = password.front();
			if (temp <= (count % 5) + 1) {
				finish = true;
				temp = 0;
			}
			else {
				temp -= (count % 5) + 1;
				count++;
			}

			password.pop();
			password.push(temp);
		}

		cout << "#" << test << " ";
		for (int i = 0; i < 8; i++) {
			cout << password.front() << " ";
			password.pop();
		}
		cout << "\n";
	}
	return 0;
}