#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		long long input;
		cin >> input;
		long long result = -1;
		for (long long i = 1; i * i * i <= input; i++) {
			if (i * i * i == input) {
				result = i;
				break;
			}
		}
		cout << '#' << a << ' ' << result << '\n';
	}

	return 0;
}