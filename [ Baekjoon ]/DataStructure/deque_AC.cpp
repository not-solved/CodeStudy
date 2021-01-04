#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	while (N--) {
		string com, arr;
		int num;
		cin >> com >> num >> arr;
		deque<int> D;
		int index = 0;
		while (arr[index] != ']') {
			int n = 0;
			index++;
			while (arr[index] != '[' && arr[index] != ',' && arr[index] != ']') {
				n *= 10;
				n += arr[index] - '0';
				index++;
			}
			if (n != 0)
				D.push_back(n);
		}
		int check = 0;
		bool err = false;

		for (int i = 0; i < com.size(); i++) {
			if (com[i] == 'R')
				check++;
			else if (com[i] == 'D') {
				if (D.empty()) {
					err = true;
					break;
				}
				if (check % 2 == 1)
					D.pop_back();
				else
					D.pop_front();
			}
		}

		if (err == true)
			cout << "error" << "\n";
		else {
			cout << "[";
			while (!D.empty()) {
				if (check % 2 == 1) {
					cout << D.back();
					D.pop_back();
				}
				else {
					cout << D.front();
					D.pop_front();
				}
				if (D.empty())
					break;
				else
					cout << ",";
			}
			cout << "]" << "\n";
		}
	}
	return 0;
}