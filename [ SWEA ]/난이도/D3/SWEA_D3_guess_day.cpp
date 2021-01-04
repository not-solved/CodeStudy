#include <iostream>
using namespace std;

int M[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int D[7] = { 3, 4, 5, 6, 0, 1, 2 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int month, day;
		cin >> month >> day;
		for (int i = 1; i < month; i++)
			day += M[i];
		day %= 7;
		cout << '#' << a << ' ' << D[day] << '\n';
	}
	return 0;
}