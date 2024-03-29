#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next;
	
	Node(int value) {
		this->value = value;
		this->next = NULL;
	}
	
	Node(int value, Node* next) {
		this->value = value;
		this->next = next;
	}
};

typedef Node* node;

void insert(node &root, int value) {
	if(root == NULL) {
		root = new Node(value);
		return;
	}
	node p = root;
	while(p->next != NULL) {
		p = p->next;
	}
	p->next = new Node(value);
}

void remove(node &root, int value) {
	node p = root;
	while(p->next != NULL) {
		if(p->next->value == value) {
			p->next = p->next->next;
		}
		else p = p->next;
	}
	if(root->value == value) {
		root = root->next;
	}	
}

void show(node root) {
	while(root != NULL) {
		cout << root->value << " ";
		root = root->next;
	}
	cout << endl;
}

int main() {
	node root = NULL;
	int n;
	cin >> n;
	int x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		insert(root, x);
	}
	cin >> x;
	remove(root, x);
	show(root);
	return 0;
}

