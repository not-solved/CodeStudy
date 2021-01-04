#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string temp[20000];
void mergeSort(vector<string>& a, int start, int mid, int end) {
	int first = start;
	int second = mid + 1;
	int index = start;

	while (first <= mid && second <= end) {
		if (a[first].length() < a[second].length())
			temp[index++] = a[first++];
		else if (a[first].length() == a[second].length()) {
			if (a[first].compare(a[second]) < 0)
				temp[index++] = a[first++];
			else
				temp[index++] = a[second++];
		}
		else
			temp[index++] = a[second++];
	}
	if (first > mid) {
		for (int i = second; i <= end; i++)
			temp[index++] = a[i];
	}
	else {
		for (int i = first; i <= mid; i++)
			temp[index++] = a[i];
	}

	for (int i = start; i <= end; i++) {
		a[i] = temp[i];
	}
}
void merge(vector<string>& a, int start, int end) {
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

	int n;
	cin >> n;
	vector<string> input(n);
	for (int i = 0; i < n; i++)
		cin >> input[i];
	merge(input, 0, n - 1);
	string prev;
	for (int i = 0; i < n; i++) {
		if (input[i].compare(prev) != 0) {
			cout << input[i] << "\n";
			prev = input[i];
		}
	}
	return 0;
}