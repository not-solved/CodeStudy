#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int files;
	cin >> files;
	vector<string> Files(files);
	cin >> Files[0];
	for (int i = 1; i < files; i++) {
		cin >> Files[i];
		for (int j = 0; j < Files[0].length(); j++) {
			if (Files[0][j] == '?')
				continue;
			if (Files[0][j] != Files[i][j])
				Files[0][j] = '?';
		}
	}
	cout << Files[0];
	return 0;
}