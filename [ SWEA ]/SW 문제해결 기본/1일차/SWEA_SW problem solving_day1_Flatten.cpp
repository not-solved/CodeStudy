#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int test_case = 1; test_case <= 10; test_case++) {
		int num;
		cin >> num;
		vector<int> A(100, 0);
		for (int i = 0; i < 100; i++)
			cin >> A[i];


		sort(A.begin(), A.end());
		for (int i = 0; i < num; i++) {
			if (A[99] - A[0] == 0)
				break;

			A[99]--;
			A[0]++;

			if (A[0] > A[1] || A[99] < A[98])
				sort(A.begin(), A.end());
		}
		cout << "#" << test_case << " " << A[99] - A[0] << "\n";
	}
	return 0;
}