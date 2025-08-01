#if 1
#include <iostream>

using namespace std;

struct node {
	int n;
	node* left;
	node* right;
	node(int v) : n(v), left(nullptr), right(nullptr) {}
};

node* maketree(node* cur, int num) {
	if (num > cur->n) {
		if (cur->right == nullptr) {
			node* child = new node(num);
			cur->right = child;
			return child;
		}
		else return maketree(cur->right, num);
	}
	else {
		if (cur->left == nullptr) {
			node* child = new node(num);
			cur->left = child;
			return child;
		}
		else return maketree(cur->left, num);
	}
}

void postorder(node* nd) {
	if (nd->left != nullptr) {
		postorder(nd->left);
		nd->left = nullptr;
	}
	if (nd->right != nullptr) {
		postorder(nd->right);
		nd->right = nullptr;
	}
	if (nd->left == nullptr && nd->right == nullptr) {
		cout << nd->n << "\n";
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	node* root = new node(t);

	node* curNode = root;

	while (cin >> t) {		
		if (t < curNode->n) {
			node* newNode = new node(t);
			curNode->left = newNode;
			curNode = newNode;
		}
		else curNode = maketree(root, t);
	}

	postorder(root);

	return 0;
}
#endif