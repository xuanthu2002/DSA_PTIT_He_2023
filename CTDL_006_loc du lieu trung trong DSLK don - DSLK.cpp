#include <iostream>
#include <map>

using namespace std;

struct Node {
	int value;
	Node* next;
	
	Node(int value) {
		this->value = value;
		this->next = NULL;
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

void unique(node &root) {
	node p = root;
	while(p->next != NULL) {
		node q = root;
		int cnt = 0;
		while(q != p->next) {
			if(q->value == p->next->value) {
				cnt += 1;
				break;
			}
			q = q->next;
		}
		if(cnt > 0) {
			p->next = p->next->next;
		}
		else p = p->next;
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
	map<int, bool> m;
	for(int i = 0; i < n; i++) {
		cin >> x;
//		if(m[x] == false) {
		insert(root, x);
//		}
//		m[x] = true;
	}
	unique(root);
	show(root);
	return 0;
}

