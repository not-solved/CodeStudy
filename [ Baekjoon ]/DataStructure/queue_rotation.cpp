#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> D;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		D.push_back(i + 1);
	int count = 0;
	int index = 0;
	while (true) {
		int temp;
		cin >> temp;
		if (D[index] != temp) {
			int increase = index;
			int decrease = index;
			while (D[increase] != temp && D[decrease] != temp) {
				do {
					increase = (increase + 1) % n;
				} while (D[increase] == 0);
				do {
					if (decrease <= 0)
						decrease = n - 1;
					else
						decrease--;
				} while (D[decrease] == 0);
				count++;
			}
			if (D[increase] == temp)
				index = increase;
			else
				index = decrease;
		}
		D[index] = 0;
		m--;
		if (m <= 0)
			break;
		do {
			index = (index + 1) % n;
		} while (D[index] == 0);
	}
	cout << count;
	return 0;
}