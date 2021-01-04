#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int people, input;
		cin >> people;
		int answer = people;
		int max = 0;
		for (int i = 0; i < people; i++) {
			cin >> input;
			answer += input;
			if (max < input)
				max = input;
		}
		answer += max;
		cout << '#' << a << ' ' << answer << '\n';
	}
	return 0;
}