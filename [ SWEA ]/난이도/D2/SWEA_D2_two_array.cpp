#include <iostream>
#include <vector>
using namespace std;

int result(vector<int> A, vector<int> B, int large, int small) {
	int max = 0;
	int start = 0;
	int end = small;
	for (int i = 0; i < large - small + 1; i++) {
		int sum = 0;
		for (int b = start; b < end; b++)
			sum += A[b] * B[b - i];

		if (sum > max)
			max = sum;
		start++;
		end++;
	}
	return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int x, y;
		cin >> x >> y;

		vector<int> A(x);
		vector<int> B(y);
		for (int i = 0; i < x; i++)
			cin >> A[i];
		for (int i = 0; i < y; i++)
			cin >> B[i];

		cout << "#" << a << " ";
		if (x > y)
			cout << result(A, B, x, y) << "\n";
		else
			cout << result(B, A, y, x) << "\n";
	}
	return 0;
}