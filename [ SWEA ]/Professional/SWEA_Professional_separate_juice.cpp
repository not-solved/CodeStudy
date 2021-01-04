#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int people;
		cin >> people;

		cout << "#" << a << " ";
		for (int i = 0; i < people; i++)
			cout << "1/" << people << ' ';
		cout << "\n";
	}
	return 0;
}