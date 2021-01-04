#include <iostream>
#include <vector>
using namespace std;

int map[10][10];

void snail(int size) {
	int left = 0;
	int right = size - 1;
	int floor = 0;
	int top = size - 1;

	int count = 1;
	while (count <= size * size) {
		for (int i = left; i <= right; i++) {
			map[floor][i] = count;
			count++;
		}
		floor++;
		for (int i = floor; i <= top; i++) {
			map[i][right] = count;
			count++;
		}
		right--;
		for (int i = right; i >= left; i--) {
			map[top][i] = count;
			count++;
		}
		top--;
		for (int i = top; i >= floor; i--) {
			map[i][left] = count;
			count++;
		}
		left++;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int input;
		cin >> input;

		cout << "#" << a << "\n";
		snail(input);
	}
	return 0;
}