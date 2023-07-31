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
	if(root != NULL) {
		if(root->value == parent) {
			if(c == 'L') {
				root->left = new Node(value);
			}
			else root->right = new Node(value);
		}
		else {
			addNode(root->left, parent, value, c);
			addNode(root->right, parent, value, c);
		}
	}
}

bool isEqual(node a, node b) {
	if(a == NULL && b == NULL) return true;
	if((a == NULL && b != NULL) || (a != NULL && b == NULL)) return false;
	return a->value == b->value && isEqual(a->left, b->left) && isEqual(a->right, b->right);
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

int main() {
	int t;
	cin >> t;
	while(t--) {
		node a = NULL;
		node b = NULL;
		init(a);
		init(b);
		cout << isEqual(a, b) << endl;
	}
	return 0;
}

