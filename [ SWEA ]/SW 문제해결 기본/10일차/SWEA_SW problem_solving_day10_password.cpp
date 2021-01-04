#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	for (int a = 1; a <= 10; a++) {
		int length, del_back, del_front;
		cin >> length;
		string password;
		cin >> password;

		for (int i = 1; i < password.length(); i++) {
			del_back = i;
			del_front = i - 1;
			while (password[del_front] == ' ' && del_front > 0)
				del_front--;
			if (password[del_front] == password[del_back]) {
				while (del_front > 0 || del_back < password.length()) {
					if (password[del_back] == password[del_front]) {
						password[del_back] = ' ';
						del_back++;
						password[del_front] = ' ';
						del_front--;
					}
					else
						break;
				}
				i = del_back - 1;
			}
		}
		cout << "#" << a << " ";
		for (int x = 0; x < password.size(); x++)
			if (password[x] != ' ')
				cout << password[x];
		cout << "\n";
	}
	return 0;
}