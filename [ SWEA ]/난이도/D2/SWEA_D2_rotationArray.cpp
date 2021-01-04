#include <iostream>
#include <vector>
using namespace std;

int map[7][7];
int r1[7][7];
int r2[7][7];
int r3[7][7];

void rotation(int before[][7], int after[][7], int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			after[i][j] = before[size - j - 1][i];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int size;
		cin >> size;


		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> map[i][j];

		rotation(map, r1, size);
		rotation(r1, r2, size);
		rotation(r2, r3, size);

		cout << "#" << a << "\n";
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				cout << r1[i][j];
			cout << " ";
			for (int j = 0; j < size; j++)
				cout << r2[i][j];
			cout << " ";
			for (int j = 0; j < size; j++)
				cout << r3[i][j];
			cout << endl;
		}
	}
	return 0;
}