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

string solve(node root) {
	stack<pair<node, int>> st;
	st.push({root, 1});
	node top;
	int max = -1;
	while(!st.empty()) {
		top = st.top().first;
		int d = st.top().second;
		st.pop();
		if(top->left && top->right) {
			st.push({top->left, d + 1});
			st.push({top->right, d + 1});
		}
		else if(!top->left && !top->right) {
			if(max == -1) max = d;
			else if(d != max) {
				return "No";
			}
		}
		else {
			return "No";
		}
	}
	return "Yes";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		node a = NULL;
		init(a);
		solve(a);
		cout << solve(a) << endl;
	}
	return 0;
}
