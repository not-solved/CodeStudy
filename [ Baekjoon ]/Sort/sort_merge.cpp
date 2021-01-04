#include <iostream>
#include <vector>
using namespace std;

int n;
void mergeSort(vector<int>& a, int left, int mid, int right) {
	int first = left;
	int second = mid + 1;
	int index = left;
	vector<int> temp(n);
	while (first <= mid && second <= right) {
		if (a[first] <= a[second])
			temp[index] = a[first++];
		else
			temp[index] = a[second++];
		index++;
	}

	if (first > mid) {
		for (int i = second; i <= right; i++)
			temp[index++] = a[i];
	}
	else {
		for (int i = first; i <= mid; i++)
			temp[index++] = a[i];
	}

	for (int i = left; i <= right; i++) {
		a[i] = temp[i];
	}
}
void merge(vector<int>& a, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge(a, start, mid);
		merge(a, mid + 1, end);
		mergeSort(a, start, mid, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> list(n);
	for (int i = 0; i < n; i++)
		cin >> list[i];

	merge(list, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << "\n";
	return 0;
}