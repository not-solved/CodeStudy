#include<bits/stdc++.h>
using namespace std;

vector<int> tree[100001];
int parent[100001];
bool visited[100001];

void DFS(int s, int par) {
	visited[s] = true;
	parent[s] = par;
	for (int i = 0; i < tree[s].size(); i++) {
		int index = tree[s][i];
		if (!visited[index])
			DFS(index, s);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	DFS(1, 1);
	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";

	return 0;
}
