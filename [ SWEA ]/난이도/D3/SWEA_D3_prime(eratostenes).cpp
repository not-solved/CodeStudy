#include <iostream>
#include <math.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (long i = 2; i <= 1000000; i++) {
		bool prime = true;
		if (i == 1) {
			prime = false;
		}
		for (long j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				prime = false;
				break;
			}
		}
		if (prime == true)
			cout << i << "\n";
	}
	return 0;
}