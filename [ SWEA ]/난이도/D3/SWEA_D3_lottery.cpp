#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int sum = 0, lottery, buy;
		cin >> lottery >> buy;
		vector<string> L(lottery);
		vector<string> B(buy);
		vector<int> win(lottery);
		for (int i = 0; i < lottery; i++)
			cin >> L[i] >> win[i];
		for (int i = 0; i < buy; i++)
			cin >> B[i];

		for (int i = 0; i < lottery; i++) {
			for (int j = 0; j < buy; j++) {
				if (B[j][0] == 'C')
					continue;
				bool check = true;
				for (int c = 0; c < 8; c++) {
					if (L[i][c] == '*')
						continue;
					if (L[i][c] != B[j][c]) {
						check = false;
						break;
					}
				}
				if (check) {
					sum += win[i];
					B[j][0] = 'C';
				}
			}
		}
		cout << '#' << a << ' ' << sum << '\n';
	}

	return 0;
}