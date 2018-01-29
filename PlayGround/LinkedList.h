#pragma once
#include "stdafx.h"
#include <unordered_set>

using namespace std;

struct ll_Node {
	int data;
	ll_Node* next;
};

class LinkedList {
public:

	void detectAndRemoveLoop() {
		ll_Node *current = start;
		unordered_set<string> stringSet;
		bool noLoop = true;
		while (current->next != nullptr && noLoop) {
			std::stringstream ss;
			ss << addressof(current);
			string address = ss.str();
			cout << "Address: " << address << "  Data: " << current->data<< std::endl;
			// Contains this address
			if (stringSet.find(address) != stringSet.end()) {
				cout << "Loop Found\n";
				current->next = nullptr;
				noLoop = false;
			} else {
				stringSet.emplace(address);
				current = current->next;
			}
		}
		if(noLoop) cout << "No Loop\n";
	}

	void createLinkedList(ll_Node* n) {
		this->start = n;
	}
	static ll_Node* newNode(int data) {
		ll_Node *temp = new ll_Node;
		temp->data = data;
		temp->next = nullptr;
		return temp;
	}
private:
	ll_Node* start;
};

void initLinkedList() {
	LinkedList lList;
	ll_Node *list = LinkedList::newNode(0);
	list->next = LinkedList::newNode(1);
	list->next->next = LinkedList::newNode(2);
	list->next->next->next = LinkedList::newNode(3);
	list->next->next->next->next = LinkedList::newNode(4);
	list->next->next->next->next->next = LinkedList::newNode(5);
	list->next->next->next->next->next->next = list;
	lList.createLinkedList(list);
	lList.detectAndRemoveLoop();
}