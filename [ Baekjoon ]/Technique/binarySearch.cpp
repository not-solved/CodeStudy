#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
void binarySearch(vector<int>& a, int target, int start, int end) {
	int mid = (start + end) / 2;
	if (target == a[mid]) {
		cout << 1 << "\n";
		return;
	}
	else if (start >= end) {
		cout << 0 << "\n";
		return;
	}

	if (target > a[mid])
		binarySearch(a, target, mid + 1, end);
	else if (target < a[mid])
		binarySearch(a, target, start, mid - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> list(n);
	for (int i = 0; i < n; i++)
		cin >> list[i];
	sort(list.begin(), list.end());

	int num;
	cin >> num;
	int target;
	while (num--) {
		cin >> target;
		binarySearch(list, target, 0, n - 1);
	}
	return 0;
}