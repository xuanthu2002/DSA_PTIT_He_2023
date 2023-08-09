#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
	
	Node(int _value) {
		value = _value;
		left = right = NULL;
	}
};

typedef Node* node;

void addNode(node root, int u, int v, char x) {
	if(root != NULL) {
		if(root->value == u) {
			if(x == 'L') {
				root->left = new Node(v);
			}
			else root->right = new Node(v);
		}
		else {
			addNode(root->left, u, v, x);
			addNode(root->right, u, v, x);
		}
	}
}

void init(node &root) {
	int n;
	cin >> n;
	int u, v;
	char x;
	cin >> u >> v >> x;
	root = new Node(u);
	addNode(root, u, v, x);
	n -= 1;
	while(n--) {
		cin >> u >> v >> x;
		addNode(root, u, v, x);
	}
}

int solve(node root, int &sum) {
	if(root == NULL) return 0;
	if(!root->left && !root->right) return root->value;
	int l = solve(root->left, sum);
	int r = solve(root->right, sum);
	if(root->left && root->right) {
		sum = max(sum, l + r + root->value);
		return max(l, r) + root->value;
	}
	if(!root->left) return r + root->value;
	if(!root->right) return l + root->value;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		node root = NULL;
		init(root);
		int sum = -1e9;
		solve(root, sum);
		cout << sum << endl;
	}
	return 0;
}

