#include <iostream>
#include <queue>
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

bool solve(node root) {
	queue<pair<node, int>> q;
	q.push({root, 1});
	int max = -1;
	while(!q.empty()) {
		node top = q.front().first;
		int d = q.front().second;
		q.pop();
		if(top->left == NULL && top->right == NULL) {
			if(max == -1) {
				max = d;
			}
			else if(d != max) {
				return false;
			} 
		}
		if(top->left != NULL) {
			q.push({top->left, d + 1});
			max = d + 1;
		}
		if(top->right != NULL) {
			q.push({top->right, d + 1});
			max = d + 1;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		node a = NULL;
		init(a);
		cout << solve(a) << endl;
	}
	return 0;
}

