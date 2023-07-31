#include <iostream>
#include <unordered_map>

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

void init(node &root) {
	int n;
	cin >> n;
	int u, v;
	char x;
	cin >> u >> v >> x;
	unordered_map<int, node> m;
	root = new Node(u);
	m[u] = root;
	if(x == 'L') {
		root->left = new Node(v);
		m[v] = root->left;
	}
	else {
		root->right = new Node(v);
		m[v] = root->right;
	}
	n -= 1;
	while(n--) {
		cin >> u >> v >> x;
		if(x == 'L') {
			m[u]->left = new Node(v);
			m[v] = m[u]->left;
		}
		else {
			m[u]->right = new Node(v);
			m[v] = m[u]->right;
		}
	}
}

long long solve(node root) {
	long long kq = 0;
	if(root != NULL) {
		if(root->right != NULL) {
			if(root->right->left == NULL && root->right->right == NULL) {
				kq += root->right->value;
			}
		}
		kq += solve(root->left) + solve(root->right);
	}
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		node root = NULL;
		init(root);
		cout << solve(root) << endl;
	}
	return 0;
}

