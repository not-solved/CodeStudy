#include <iostream>
#include <queue>
using namespace std;

void Insert(deque<int>& D) {
	deque<int> temp1;
	deque<int> temp2;
	int index, coms, fix;
	cin >> index >> coms;
	for (int j = 0; j < index; j++) {
		temp1.push_back(D.front());
		D.pop_front();
	}
	for (int j = 0; j < coms; j++) {
		cin >> fix;
		temp2.push_back(fix);
	}
	while (!temp2.empty()) {
		D.push_front(temp2.back());
		temp2.pop_back();
	}
	while (!temp1.empty()) {
		D.push_front(temp1.back());
		temp1.pop_back();
	}
}
void Delete(deque<int>& D) {
	deque<int> temp1;
	int index, size;
	cin >> index >> size;
	for (int j = 0; j < index; j++) {
		temp1.push_back(D.front());
		D.pop_front();
	}
	for (int j = 0; j < size; j++) {
		D.pop_front();
	}
	while (!temp1.empty()) {
		D.push_front(temp1.back());
		temp1.pop_back();
	}
}
void Add(deque<int>& D) {
	int size, add_on;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> add_on;
		D.push_back(add_on);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	for (int a = 1; a <= 10; a++) {
		int n, input, com;
		char command;

		cin >> n;
		deque<int> bottle;
		for (int i = 0; i < n; i++) {
			cin >> input;
			bottle.push_back(input);
		}
		cin >> com;
		for (int i = 0; i < com; i++) {
			cin >> command;
			if (command == 'I')
				Insert(bottle);
			else if (command == 'D')
				Delete(bottle);
			else if (command == 'A')
				Add(bottle);
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