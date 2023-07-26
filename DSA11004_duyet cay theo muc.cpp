#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int infor;
	Node *left;
	Node *right;
	
	Node () {}
	
	Node (int n) {
		infor = n;
		left = right = NULL;
	}
};

void insertNode(Node* &T, int n, char c) {
	switch(c) {
		case('L') : {
			T->left = new Node (n);
			break;
		}
		case('R') : {
			T->right = new Node (n);
			break;
		}
	}
}

void insert(Node* &T, int p, int n, char c) {
	if(T->infor == p) {
		insertNode(T, n, c);
		return;
	}
	if (T->left != NULL) {
		insert(T->left, p, n, c);
	}
	if(T->right != NULL) {
		insert(T->right, p, n, c);
	}
}

void BFS(Node* T) {
	queue<Node*> q;
	q.push(T);
	while(!q.empty()) {
		Node* top = q.front();
		q.pop();
		cout << top->infor << " ";
		if(top->left != NULL) {
			q.push(top->left);
		}
		if(top->right != NULL) {
			q.push(top->right);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int m;
		cin >> m;
		Node *T = NULL;
		int p, n;
		char c;
		for(int i = 0; i < m; i++) {
			cin >> p >> n >> c;
			if(T == NULL) {
				T = new Node (p);
				insertNode(T, n, c);
			}
			else {
				insert(T, p, n, c);
			}
		}
		BFS(T);
		cout << endl;
	}
	return 0;
}


