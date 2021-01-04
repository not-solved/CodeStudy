#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int sum = 0;
	vector<int> input(n);
	vector<pair<int, int>> list(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		sum += input[i];
	}
	sort(input.begin(), input.end());
	double avg = (double)sum / n;
	avg = floor(avg + 0.5);
	int range = input[n - 1] - input[0];
	int mid = input[n / 2];

	int mode;
	int cur = input[0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (cur == input[i]) {
			cnt++;
		}
		else {
			list.push_back(make_pair(cur, cnt));
			cur = input[i];
			cnt = 1;
		}
	}
	list.push_back(make_pair(cur, cnt));

	sort(list.begin(), list.end(), comp);
	if (list.size() >= 2 && list[0].second == list[1].second) {
		mode = list[1].first;
	}
	else {
		mode = list[0].first;
	}

	cout << avg << "\n" << mid << "\n" << mode << "\n" << range;
	return 0;
}