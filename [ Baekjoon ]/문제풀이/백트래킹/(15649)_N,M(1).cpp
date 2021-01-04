#include <iostream>
#include <vector>
using namespace std;

vector<int> print;
bool visited[9] = { false, };
int N, M;

void AA(int i) {
	
	int j;
	if (i == 0) {
		for (int a = 0; a < M; a++) {
			cout << print[a] << " ";
		}
		cout << "\n";
		return;
	}
	for (int a = 1; a <= N; a++) {
		if (!visited[a]) {
			visited[a] = true;
			print.push_back(a);
			AA(i - 1);
			visited[a] = false;
			print.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	AA(M);

	return 0;
}