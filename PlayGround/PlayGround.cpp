// PlayGround.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Utils.h"
#include "RandomTasks.h"
#include "GeeksForGeeksMedium.h"
#include "BinaryTree.h"
#include "LinkedList.h"
using namespace std;

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

