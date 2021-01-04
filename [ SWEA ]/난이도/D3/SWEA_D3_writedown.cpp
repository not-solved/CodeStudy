#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int size;
		cin >> size;
		string input, comp;
		cin >> input >> comp;
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (input[i] == comp[i])
				count++;
		}


		cout << "#" << a << " " << count << "\n";
	}
	return 0;
}