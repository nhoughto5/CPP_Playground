// PlayGround.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Utils.h"
#include "RandomTasks.h"
#include "GeeksForGeeksMedium.h"
#include "BinaryTree.h"
#include "LinkedList.h"
using namespace std;

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

void templateVectorSort() {
	vector<int> ints = {2000, 456, -10, 9};
	templateSort(ints);
	printVector(ints);
	vector<string> str = {"We do nothing",
		"Hi I have something",
		"Hello Join something!",
		"(Why to do work)"};
	templateSort(str);
	printVector(str);
}

class Base {
public:
	virtual void shout() {
		cout << "Base\n";
	}
};
class Derived : public Base {
public:
	void shout() override {
		cout << "Derived\n";
	}
};


int main() {

	return 0;
}

