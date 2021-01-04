#include <iostream>
#include <vector>
using namespace std;

void NM(vector<int> print, bool visited[], int N, int M, int a) {
	if (a == 0) {
		for (int i = 0; i < M; i++)
			cout << print[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if(print.empty() || (!print.empty() && print.back() <= i)) {
			visited[i] = true;
			print.push_back(i);
			NM(print, visited, N, M, a - 1);
			print.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> A;
	bool visited[9] = { false, };
	A.clear();
	int N, M;
	cin >> N >> M;
	NM(A, visited, N, M, M);

	return 0;
}