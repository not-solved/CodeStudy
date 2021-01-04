#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	for (int a = 1; a <= 10; a++) {
		int n, input, com, coms, index, fix;
		char command;

		cin >> n;
		deque<int> bottle;
		for (int i = 0; i < n; i++) {
			cin >> input;
			bottle.push_back(input);
		}
		cin >> com;
		deque<int> temp1;
		deque<int> temp2;
		for (int i = 0; i < com; i++) {
			cin >> command >> index >> coms;
			for (int j = 0; j < index; j++) {
				temp1.push_back(bottle.front());
				bottle.pop_front();
			}
			for (int j = 0; j < coms; j++) {
				cin >> fix;
				temp2.push_back(fix);
			}
			while (!temp2.empty()) {
				bottle.push_front(temp2.back());
				temp2.pop_back();
			}
			while (!temp1.empty()) {
				bottle.push_front(temp1.back());
				temp1.pop_back();
			}
		}

		cout << "#" << a << " ";
		for (int i = 0; i < 10; i++) {
			if (bottle.empty())
				break;
			cout << bottle.front() << " ";
			bottle.pop_front();
		}
		cout << "\n";
	}
	return 0;
}