#include<iostream>
using namespace std;

int sudoku[9][9];

int main(int argc, char** argv) {
	int test_case, T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		bool check = true;
		int sum_vertical[9] = { 0, };
		int sum_horizon[9] = { 0, };
		int sum_box[9] = { 0, };
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> sudoku[i][j];
				sum_vertical[i] += sudoku[i][j];
				sum_horizon[j] += sudoku[i][j];
				sum_box[(i / 3) * 3 + (j / 3)] += sudoku[i][j];
			}
		}
		for (int i = 0; i < 9; i++) {
			if (sum_vertical[i] != 45 || sum_horizon[i] != 45 || sum_box[i] != 45) {
				check = false;
				break;
			}
		}
		cout << "#" << test_case << " ";
		if (!check)
			cout << 0 << "\n";
		else
			cout << 1 << "\n";

	}
	return 0;
}