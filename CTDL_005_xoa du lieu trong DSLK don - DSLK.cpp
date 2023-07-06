#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* next = NULL;
	
	Node(int value) {
		value = value;
		next = NULL;
	}
};

void insert(Node* root, int value) {
	Node node = *root;
	if(node == NULL) {
		node = new Node(value);
		return;
	}
	while(node.next != NULL) {
		node = *(node.next);
	}
	node.next = new Node(value);
}

void delete(Node* root, int value) {
	Node node = *root;
	while(node.next != NULL) {
		if(node.value == value) {
			node = *(node.next);
		}
	}
}

int main() {
	
	return 0;
}

