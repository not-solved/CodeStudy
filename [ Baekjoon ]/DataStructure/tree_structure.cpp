#include <iostream>
using namespace std;

struct node {
	char num;
	node* left;
	node* right;
};
void inorder(node* n) {
	if (n != NULL) {
		inorder(n->left);
		cout << n->num << " ";
		inorder(n->right);
	}
}
void preorder(node* n) {
	if (n != NULL) {
		cout << n->num << " ";
		preorder(n->left);
		preorder(n->right);
	}
}
void postorder(node* n) {
	if (n != NULL) {
		postorder(n->left);
		postorder(n->right);
		cout << n->num << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 7;
	char i, j, k;

	node n4 = { 'D', NULL, NULL };
	node n5 = { 'E', NULL, NULL };
	node n6 = { 'F', NULL, NULL };
	node n7 = { 'G', NULL, NULL };
	node n3 = { 'C', &n6, &n7 };
	node n2 = { 'B', &n4, &n5 };
	node n1 = { 'A', &n2, &n3 };
	node* root = &n1;
	inorder(root);
	cout << endl;
	preorder(root);
	cout << endl;
	postorder(root);
	return 0;
}