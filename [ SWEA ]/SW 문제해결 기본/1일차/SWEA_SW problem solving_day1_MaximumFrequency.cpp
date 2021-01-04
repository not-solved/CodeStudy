#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int test;
		cin >> test;
		int score;
		vector<pair<int, int>> V(101, make_pair(0, 0));
		for (int i = 0; i < 1000; i++) {
			cin >> score;
			V[score].first++;
			V[score].second = score;
		}
		sort(V.begin(), V.end());
		int value = V[100].first;
		int max = V[100].second;
		for (int i = 99; i >= 0; i--) {
			if (value > V[i].first)
				break;
			if (max < V[i].second)
				max = V[i].second;
		}
		cout << "#" << test << " " << max << "\n";
	}
	return 0;
}