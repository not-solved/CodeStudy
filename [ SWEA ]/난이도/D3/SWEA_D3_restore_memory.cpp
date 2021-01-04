#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string input;
		cin >> input;
		int count = 0;
		if (input[0] == '1')
			count++;
		for (int i = 1; i < input.size(); i++)
			if (input[i - 1] != input[i])
				count++;

		cout << "#" << a << " " << count << "\n";
	}
	return 0;
}