#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string passcode[10] = { "0001101", "0011001", "0010011", "0111101", "0100011",
						"0110001", "0101111", "0111011", "0110111", "0001011" };
int check[8];
string map[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int n, m;
		cin >> n >> m;
		int index_x = 0;
		int index_y = 0;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
			for (int j = map[i].size() - 1; j >= 0; j--) {
				if (map[i][j] == '1') {
					index_y = i;
					index_x = j;
					break;
				}
			}
		}
		int sum = 0;
		int index_check = 7;
		for (int i = 0; i < 8; i++) {
			string comp = map[index_y].substr(index_x - 6, 7);
			index_x -= 7;
			for (int j = 0; j < 10; j++) {
				if (!comp.compare(passcode[j])) {
					check[index_check--] = j;
					break;
				}
			}
		}
		if (((check[0] + check[2] + check[4] + check[6]) * 3 + check[1] + check[3] + check[5] + check[7]) % 10 == 0)
			for (int j = 0; j < 8; j++)
				sum += check[j];
		cout << '#' << a << ' ' << sum << '\n';
	}
	return 0;
}