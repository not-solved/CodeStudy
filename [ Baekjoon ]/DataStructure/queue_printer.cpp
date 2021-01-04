#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int a = 0; a < N; a++) {
		int documents, target;
		cin >> documents >> target;
		int input;
		vector<int> A;
		priority_queue<int> B;
		for (int j = 0; j < documents; j++) {
			cin >> input;
			A.push_back(input);
			B.push(input);
		}
		int i = 0;
		int count = 1;
		while (true) {
			if (A[i] >= B.top()) {
				if (i == target) {
					cout << count << "\n";
					break;
				}
				else {
					A[i] = 0;
					B.pop();
					count++;
				}
			}
			i = (i + 1) % documents;
		}
	}
	return 0;
}