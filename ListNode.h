#pragma once
#ifndef ListNode

#include<iostream>

using namespace std;

template<typename T>
class ListNode {
private:

public:
	ListNode<T>* prev;
	ListNode<T>* next;
	T data;

	ListNode(T data) {
		this->data = data;
		this->prev = this->next = NULL;
	}

	ListNode() {
		this->data = NULL;
		this->prev = this->next = NULL;
	}
};
#endif // !ListNode