#include <iostream>
#include <stack>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
	
	Node (int x) {
		data = x;
		left = right = NULL;
	}
};

typedef Node* node;

node search(node root, int x) {
	if(root == NULL) return NULL;
	if(root->data == x) return root;
	node p = search(root->left, x);
	if(!p) {
		p = search(root->right, x);
	}
	return p;
}

void addLeft(node &root, int x, int y) {
	node p = search(root, x);
	if(p == NULL) {
		cout << "Khong ton tai node x" << endl;
		return;
	}
	if(p->left != NULL) {
		cout << "Node x da co node con ben trai" << endl;
		return;
	}
	p->left = new Node(y);
}

void addRight(node &root, int x, int y) {
	node p = search(root, x);
	if(p == NULL) {
		cout << "Khong ton tai node x" << endl;
		return;
	}
	if(p->right != NULL) {
		cout << "Node x da co node con ben phai" << endl;
		return;
	}
	p->right = new Node(y);
}

void NLR(node root) {
	if(root != NULL) {
		cout << root->data << " ";
		NLR(root->left);
		NLR(root->right);
	}
}

void LRN(node root) {
	if(root != NULL) {
		LRN(root->left);
		LRN(root->right);
		cout << root->data << " ";
	}
}

void LNR(node root) {
	if(root != NULL) {
		LNR(root->left);
		cout << root->data << " ";
		LNR(root->right);
	}
}

int main() {
	node root = NULL;
	root = new Node(1);
	addLeft(root, 1, 2);
	addRight(root, 1, 3);
	NLR(root);
	cout << endl;
	LRN(root);
	cout << endl;
	LNR(root);
	return 0;
}

