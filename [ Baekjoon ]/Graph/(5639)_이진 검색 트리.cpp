#include <iostream>
#include <cstdio>
using namespace std;

struct node {
	int num;
	node* parent;
	node* left;
	node* right;
};
node* create(int a) {
	node* temp = new node;
	temp->num = a;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	return temp;
}

void insert(node* n, int a) {
	
	if (n->num > a) {
		if (n->left == NULL) {
			node* temp = create(a);
			temp->parent = n;
			n->left = temp;
		}
		else
			insert(n->left, a);
	}
	else if (n->num < a) {
		if (n->right == NULL) {
			node* temp = create(a);
			temp->parent = n;
			n->right = temp;
		}
		else
			insert(n->right, a);
	}
}
void postorder(node* n) {
	if (n != NULL) {
		postorder(n->left);
		postorder(n->right);
		cout << n->num << "\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n = 0;
	node* root = NULL;
	int count = 0;
	while (scanf("%d", &n) == 1) {
		if (n > 0)  {
			if (count == 0) {
				root = new node;
				root->num = n;
				root->left = NULL;
				root->right = NULL;
			}
			else
				insert(root, n);
			count++;
		}
	}
	postorder(root);

	return 0;
}