#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int ans = 0, input, nums;
		cin >> nums;
		for (int i = 0; i < nums; i++) {
			cin >> input;
			if (ans + input > ans* input)
				ans += input;
			else
				ans *= input;
		}
		cout << '#' << a << ' ' << ans << '\n';
	}

	return 0;
}