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

	for (int i = 0; i < N - 1; i++) {
		int j = i;
		while (A[j] > A[j + 1]) {
			int temp = A[j];
			A[j] = A[j + 1];
			A[j + 1] = temp;
			j--;
		}
	}
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	cout << "\n";

	return 0;
}