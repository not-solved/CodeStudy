#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<long> A;
	long B;
	cin >> B;
	long temp;
	for (long i = 0; i < B; i++) {
		cin >> temp;
		A.push_back(temp);
	}

	sort(A.begin(), A.end());
	for (long i = 0; i < B; i++) {
		cout << A[i] << "\n";
	}
	return 0;
}