// PlayGround.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Utils.h"
#include "RandomTasks.h"
#include "GeeksForGeeksMedium.h"
#include "BinaryTree.h"
using namespace std;

void printBinarySortedTreesInSortedOrder() {
	Node *root = BinaryTree::newNode(1);
	root->left = BinaryTree::newNode(2);
	root->right = BinaryTree::newNode(3);
	root->left->left = BinaryTree::newNode(4);
	root->left->right = BinaryTree::newNode(5);
	//root->right->left = BinaryTree::newNode(2);
	//root->right->right = BinaryTree::newNode(1);
	BinaryTree tree;
	tree.createTree(root);
	tree.printInOrder(Postorder);
}

int main() {
	printBinarySortedTreesInSortedOrder();
	return 0;
}

