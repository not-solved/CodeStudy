#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size;
	cin >> size;
	priority_queue<int, vector<int>, greater<int>> maxP;
	priority_queue<int> minP;
	int input;
	for (int i = 0; i < size; i++) {
		cin >> input;
		if (i == 0)
			minP.push(input);
		else if (i == 1) {
			if (input < minP.top()) {
				maxP.push(minP.top());
				minP.pop();
				minP.push(input);
			}
			else
				maxP.push(input);
		}
		else {
			if (i % 2 == 0) {
				if (input > maxP.top()) {
					minP.push(maxP.top());
					maxP.pop();
					maxP.push(input);
				}
				else {
					minP.push(input);
				}
			}
			else {
				if (input < minP.top()) {
					maxP.push(minP.top());
					minP.pop();
					minP.push(input);
				}
				else {
					maxP.push(input);
				}
			}
		}
		cout << minP.top() << "\n";
	}
	return 0;
}