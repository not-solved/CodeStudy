#include <iostream>
using namespace std;

int map[21][21];
bool visited[21];
int minimum = 1000000000;

int teamStart[11];
int teamLink[11];
int Size;
int target_size;

int MIN(int a, int b) {
	return (a < b) ? a : b;
}
int ABS(int a) {
	return (a < 0) ? -a : a;
}

void DFS(int index, int count) {

	if(count == target_size) {
		int link_i = 0;
		for (int i = 1; i <= Size; i++) {
			if (!visited[i]) {
				teamLink[link_i++] = i;
			}
		}

		int sum_Start = 0;
		for (int i = 0; i < target_size - 1; i++)
			for (int j = i + 1; j < target_size; j++)
				sum_Start += (map[teamStart[i]][teamStart[j]] + map[teamStart[j]][teamStart[i]]);
		int sum_Link = 0;
		for (int i = 0; i < target_size - 1; i++)
			for (int j = i + 1; j < target_size; j++)
				sum_Link += (map[teamLink[i]][teamLink[j]] + map[teamLink[j]][teamLink[i]]);

		minimum = MIN(minimum, ABS(sum_Start - sum_Link));
		return;
	}
	for (int i = index + 1 ; i <= Size; i++) {
		if (!visited[i]) {
			visited[i] = true;
			teamStart[count] = i;
			DFS(i, count + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Size;
	for (int i = 1; i <= Size; i++)
		for (int j = 1; j <= Size; j++)
			cin >> map[i][j];
	target_size = Size / 2;
	DFS(0, 0);
	cout << minimum;
	return 0;
}