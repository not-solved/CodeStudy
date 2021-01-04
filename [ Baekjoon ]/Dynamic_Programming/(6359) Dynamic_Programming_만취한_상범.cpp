#include <iostream>
using namespace std;

int Prison[101] = { 0, };
int Escape[101] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int temp = 1;
	while (temp * temp < 101) {
		Prison[temp * temp] = 1;
		temp++;
	}
	for (int i = 1; i < 101; i++) {
		if (Prison[i] == 1)
			Escape[i] = Escape[i - 1] + 1;
		else
			Escape[i] = Escape[i - 1];
	}
	int loop;
	cin >> loop;
	while (loop--) {
		int rooms;
		cin >> rooms;
		cout << Escape[rooms] << '\n';
	}
	return 0;
}