#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int tree[1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int depth, input;
		cin >> depth;
		queue<int> rotate;
		for (int i = 1; i < pow(2, depth); i++) {
			cin >> input;
			rotate.push(input);
		}
		int depth_temp = depth;
		while (!rotate.empty()) {
			int temp;
			int index = pow(2, depth - 1);
			for (int i = 1; i < pow(2, depth); i++) {
				temp = rotate.front();
				rotate.pop();
				if (i % 2 != 0) {
					tree[index++] = temp;
				}
				else
					rotate.push(temp);
			}
			depth--;
		}
		cout << '#' << a << ' ';
		int level = 1;
		int count = 1;
		for (int i = 1; i < pow(2, depth_temp); i++) {
			int lv = pow(2, level - 1);
			cout << tree[i] << ' ';
			if (count % lv == 0) {
				cout << "\n";
				count = 0;
				level++;
			}
			count++;
		}
	}
	return 0;
}