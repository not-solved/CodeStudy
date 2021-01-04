#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A[1000];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (A[j] > A[j + 1]) {
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << A[i] << "\n";

	return 0;
}