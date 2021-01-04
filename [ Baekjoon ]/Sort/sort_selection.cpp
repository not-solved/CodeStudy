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

	int min, index;
	for (int i = 0; i < N; i++) {
		min = 1001;
		index = 0;
		for (int j = i; j < N; j++) {
			if (A[j] < min) {
				min = A[j];
				index = j;
			}
		}
		int temp = A[i];
		A[i] = min;
		A[index] = temp;
	}
	for (int i = 0; i < N; i++)
		cout << A[i] << "\n";

	return 0;
}