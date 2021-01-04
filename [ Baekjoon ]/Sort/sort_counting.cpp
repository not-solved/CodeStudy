#include <iostream>
#include <cstring>
#define MAX	10001
using namespace std;

int sort[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(sort, 0, MAX);
	long long n;
	cin >> n;
	int temp;
	for (long long i = 0; i < n; i++) {
		cin >> temp;
		sort[temp]++;
	}
	bool end = false;
	int index = 0;
	while (n > 0) {
		if (sort[index] == 0)
			index++;
		else {
			cout << index << "\n";
			sort[index]--;
			n--;
		}
	}
	return 0;
}