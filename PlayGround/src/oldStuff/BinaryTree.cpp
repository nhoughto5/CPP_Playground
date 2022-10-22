#include "BinaryTree.h"

BinaryTree::BinaryTree() : height(0), root(nullptr) {}


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
	this->height = this->treeHeight();
	std::cout << "Tree Height: " << this->height << std::endl;
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

void BinaryTree::printLevelOrder() {
	for (int d = 1; d <= this->height; ++d) {
		printGivenLevel(d, this->root, false);
	}
	std::cout << "\n";
}

void BinaryTree::printGivenLevel(int d, Node* node, bool sorted = false) {
	if (node == NULL) return;
	if (d == 1) std::cout << node->data << " ";
	else {
		if (sorted) {
			if (node->left->data < node->right->data) {
				printGivenLevel(d - 1, node->left, true);
				printGivenLevel(d - 1, node->right, true);
			} else {
				printGivenLevel(d - 1, node->right, true);
				printGivenLevel(d - 1, node->left, true);
			}
		} else {
			printGivenLevel(d - 1, node->left);
			printGivenLevel(d - 1, node->right);
		}
	}
}

void BinaryTree::printSortedLevels() {
	for (int d = 1; d <= this->height; ++d) {
		this->printGivenLevel(d, this->root, true);
		std::cout << "\n";
	}
	std::cout << "\n";
}

int BinaryTree::treeHeight() {
	if (this->root == NULL || this->root == nullptr) {
		return 0;
	}

	std::queue<Node *> q;
	q.push(root);
	int h = 0;
	while (1) {
		int nodeCount = q.size();
		if (nodeCount == 0) return height;
		++height;
		while (nodeCount > 0) {
			Node* node = q.front();
			q.pop();
			if (node->left != NULL) {
				q.push(node->left);
			}
			if (node->right != NULL) {
				q.push(node->right);
			}
			nodeCount--;
		}
	}
}
