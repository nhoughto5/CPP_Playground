#include "stdafx.h"
#include "BinaryTree.h"


BinaryTree::BinaryTree() {}


BinaryTree::~BinaryTree() {}

Node * BinaryTree::newNode(int d) {
	Node* temp = new Node();
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void BinaryTree::createTree(Node * r) {
	this->root = r;
}

void BinaryTree::printInOrder(TRAVERAL_ORDER order) {
	this->printInOrder(this->root, order);
	std::cout << "\n";
}

void BinaryTree::printInOrder(Node* r, TRAVERAL_ORDER order) {
	if (r == NULL) return;
	switch (order) {
		case Inorder:
			this->printInOrder(r->left, order);
			std::cout << r->data << " ";
			this->printInOrder(r->right, order);
			break;
		case Preorder:
			std::cout << r->data << " ";
			this->printInOrder(r->left, order);
			this->printInOrder(r->right, order);
			break;
		case Postorder:
			this->printInOrder(r->left, order);
			this->printInOrder(r->right, order);
			std::cout << r->data << " ";
			break;
		default:
			break;
	}

}