#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
	
	Node(int a) {
		value = a;
		left = right = NULL;
	}
};

typedef Node* node;

void addNode(node &root, int parent, int value, char c) {
	if(root == NULL) return;
	if(root->value == parent) {
		if(c == 'L') {
			root->left = new Node(value);
		}
		else {
			root->right = new Node(value);
		}
		return;
	}
	addNode(root->left, parent, value, c);
	addNode(root->right, parent, value, c);
}

bool isFull(node root) {
	if(root->left == NULL && root->right == NULL) {
		return true;
	}
	else if(root->left == NULL && root->right != NULL || root->left != NULL && root->right == NULL)
		return false;
	return isFull(root->left) && isFull(root->right);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int u, v;
		char x;
		node root = NULL;
		while(n--) {
			cin >> u >> v >> x;
			if(root == NULL) {
				root = new Node(u);
			}
			addNode(root, u, v, x);
		}
		cout << isFull(root) << endl;
	}
	return 0;
}

