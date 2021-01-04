#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	string com;
	int num;
	deque<int> D;
	while (N--) {
		cin >> com;
		if (!com.compare("push_front")) {
			cin >> num;
			D.push_front(num);
		}
		else if (!com.compare("push_back")) {
			cin >> num;
			D.push_back(num);
		}
		else if (!com.compare("pop_front")) {
			if (D.empty())
				cout << -1 << "\n";
			else {
				cout << D.front() << "\n";
				D.pop_front();
			}
		}
		else if (!com.compare("pop_back")) {
			if (D.empty())
				cout << -1 << "\n";
			else {
				cout << D.back() << "\n";
				D.pop_back();
			}
		}
		else if (!com.compare("front")) {
			if (D.empty())
				cout << -1 << "\n";
			else
				cout << D.front() << "\n";
		}
		else if (!com.compare("back")) {
			if (D.empty())
				cout << -1 << "\n";
			else
				cout << D.back() << "\n";
		}
		else if (!com.compare("size"))
			cout << D.size() << "\n";
		else if (!com.compare("empty"))
			cout << D.empty() << "\n";
		else
			cout << "incorrect command\n";
	}
	return 0;
}