#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string input;
		cin >> input;
		int h, in;
		cin >> h;
		priority_queue<int, vector<int>, greater<int>> P;
		for (int i = 0; i < h; i++) {
			cin >> in;
			P.push(in);
		}
		cout << '#' << a << ' ';
		for (int i = 0; i < input.size(); i++) {
			while (i == P.top() && !P.empty()) {
				cout << '-';
				P.pop();
			}
			cout << input[i];
		}
		while (!P.empty()) {
			cout << '-';
			P.pop();
		}
		cout << '\n';
	}
	return 0;
}