#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int loop;
	cin >> loop;
	for (int a = 1; a <= loop; a++) {
		int N, Q, L, R;
		cin >> N >> Q;
		vector<int> V(N + 1, 0);
		for (int i = 1; i <= Q; i++) {
			cin >> L >> R;
			for (int j = L; j <= R; j++)
				V[j] = i;
		}
		cout << '#' << a << ' ';
		for (int i = 1; i <= N; i++)
			cout << V[i] << ' ';
		cout << '\n';
	}
	return 0;
}