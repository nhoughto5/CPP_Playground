#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#include <tchar.h>
enum TRAVERAL_ORDER{ Inorder, Preorder, Postorder};
struct Node {
	int data;
	Node *left, *right;
};
class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	static Node* newNode(int data);
	void createTree(Node* root);
	void printInOrder(TRAVERAL_ORDER order);
	void printInOrder(Node * r, TRAVERAL_ORDER order);
	void printLevelOrder();
	void printGivenLevel(int d, Node* node, bool sorted);
	void printSortedLevels();
private:

	int treeHeight();

	Node* root;
	int height;
};

void printBinarySortedTreesInSortedOrder() {
	Node *root = BinaryTree::newNode(7);
	root->left = BinaryTree::newNode(6);
	root->right = BinaryTree::newNode(5);
	root->left->left = BinaryTree::newNode(4);
	root->left->right = BinaryTree::newNode(3);
	root->right->left = BinaryTree::newNode(2);
	root->right->right = BinaryTree::newNode(1);
	BinaryTree tree;
	tree.createTree(root);
	//tree.printInOrder(Postorder);
	tree.printSortedLevels();
}
