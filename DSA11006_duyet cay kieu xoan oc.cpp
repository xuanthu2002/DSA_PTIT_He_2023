#include <iostream>
#include <stack>
#include <utility>

using namespace std;

struct Node {
	int value;
	Node *left;
	Node *right;
	
	Node() {}
	Node(int a) {
		value = a;
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
			else {
				root->right = new Node(v);
			}
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
	n -= 1;
	root = new Node(u);
	addNode(root, u, v, x);
	while(n--) {
		cin >> u >> v >> x;
		addNode(root, u, v, x);
	}
}

void solve(node root) {
	if(root == NULL) return;
	stack<node> st1, st2;
	st1.push(root);
	node top;
	while(!st1.empty() || !st2.empty()) {
		while(!st1.empty()) {
			top = st1.top();
			st1.pop();
			cout << top->value << " ";
			if(top->right != NULL) {
				st2.push(top->right);
			}
			if(top->left != NULL) {
				st2.push(top->left);
			}
		}
		while(!st2.empty()) {
			top = st2.top();
			st2.pop();
			cout << top->value << " ";
			if(top->left != NULL) {
				st1.push(top->left);
			}
			if(top->right != NULL) {
				st1.push(top->right);
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		node a = NULL;
		init(a);
		solve(a);
		cout << endl;
	}
	return 0;
}
