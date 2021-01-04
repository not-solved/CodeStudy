#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int count;
		cin >> count;
		vector<string> input(count);
		for (int i = 0; i < count; i++)
			cin >> input[i];
		sort(input.begin(), input.end());

		if (input[0][0] != 'A') {
			cout << '#' << a << ' ' << 0 << '\n';
			continue;
		}
		int result = 1;
		for (int i = 1; i < count; i++) {
			if (input[i][0] == input[i - 1][0])
				continue;
			else if ((input[i][0] == input[i - 1][0] + 1))
				result++;
			else
				break;
		}
		cout << '#' << a << ' ' << result << '\n';
	}
	return 0;
}