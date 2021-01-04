#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b, a_temp, b_temp, gcd;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (b > a) {
			a_temp = b;
			b_temp = a;
		}
		else {
			a_temp = a;
			b_temp = b;
		}
		while (true) {
			if (a_temp % b_temp == 0) {
				gcd = b_temp;
				break;
			}
			else {
				a_temp = (a_temp % b_temp);
				b_temp = (b_temp % a_temp);
			}
		}
		cout << a * b / gcd << "\n";
	}
	return 0;
}