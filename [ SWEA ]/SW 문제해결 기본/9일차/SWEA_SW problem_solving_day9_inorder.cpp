#include <iostream>
#include <vector>
using namespace std;

char word[101];
vector<int> vertex[101];

void inorder(int index) {
	if (vertex[index].size() == 1) {
		inorder(index * 2);
		cout << word[index];
	}
	else if (vertex[index].size() == 2) {
		inorder(index * 2);
		cout << word[index];
		inorder(index * 2 + 1);
	}
	else if (vertex[index].size() == 0)
		cout << word[index];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int a = 1; a <= 10; a++) {
		int size;
		cin >> size;
		int num, left, right;
		for (int i = 0; i < size; i++) {
			cin >> num;
			cin >> word[num];

			if (num * 2 <= size) {
				cin >> left;
				vertex[num].push_back(left);
			}
			if (num * 2 + 1 <= size) {
				cin >> right;
				vertex[num].push_back(right);
			}
		}

		cout << "#" << a << " ";
		inorder(1);
		cout << "\n";
		for (int i = 0; i < size; i++)
			vertex[i].clear();
	}
	return 0;
}