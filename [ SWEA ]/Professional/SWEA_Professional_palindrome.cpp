#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		string input;
		cin >> input;
		vector<int> index[26];
		vector<int> amount(26, 0);

		for (int i = 0; i < input.size(); i++) {
			index[input[i] - 65].push_back(i);
		}
		for (int i = 0; i < 26; i++)
			amount[i] = index[i].size();

		int length = 0;
		int max = 0;
		int start, end;
		for (int i = 0; i < 26; i++) {
			if (amount[i] < 1)
				continue;
			for (int j = 0; j < amount[i]; j++) {
				start = index[i][j];
				int end_index = amount[i] - 1;
				// cout << "current : " << input[start] << " index : " << start << endl;
				while (end_index >= j) {
					length = 0;
					end = index[i][end_index];
					int s_temp = start;
					int e_temp = end;
					bool find = true;
					// cout << "index : " << end << ' ';
					while (s_temp <= e_temp) {
						if (input[s_temp] != input[e_temp]) {
							find = false;
							break;
						}
						s_temp++;
						e_temp--;
					}
					if (find)
						length = end - start + 1;
					if (max < length)
						max = length;
					end_index--;
					// cout << "result : " << find << " length : " << length << endl;
				}
			}
		}
		cout << '#' << a << ' ' << max << '\n';
	}
	return 0;
}