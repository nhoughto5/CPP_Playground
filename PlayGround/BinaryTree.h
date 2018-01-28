#pragma once
#include "stdafx.h"
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
	void printGivenLevel(int d);
private:
	Node* root;
};

