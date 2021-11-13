#pragma once
#ifndef List

#include<ListNode.h>;

template<typename T>
class List {
private:
	ListNode<T>* headNode;
	unsigned int _length;
public:
	List() {
		this->headNode = new ListNode<T>();
		this->headNode->next = this->headNode;
		this->headNode->prev = this->headNode;
		this->_length = 0;
	}

	bool empty() {
		return this->headNode->next = this->headNode;
	}

	unsigned int getLength() {
		return this._length;
	}

	ListNode<T>* begin() {
		if (this->headNode->next == NULL) {
			throw "头节点的next指针必须不为null";
		}
		return this->headNode->next;
	}

	ListNode<T>* end() {
		return this->headNode;
	}

	bool contains(T data) {
		for (ListNode<T>* link = this->headNode->next; link != NULL && link != this->headNode; link = link->next) {
			if (link->data != NULL) {
				if (data == link->data) {
					return true;
				}
			}
		}
		return false;
	}

	void forNext(void (*cb)(T data)) {
		for (ListNode<T>* link = this->headNode->next; link != NULL && link != this->headNode; link = link->next) {
			if (link->data != NULL) {
				cb(link->data);
			}
		}
	}

	void forPrev(void (*cb)(T data)) {
		for (ListNode<T>* link = this->headNode->prev; link != NULL && link != this->headNode; link = link->prev) {
			if (link->data != NULL) {
				cb(link->data);
			}
		}
	}

	ListNode<T>* insertBefore(ListNode<T>* node, T data) {
		ListNode<T>* ret = new ListNode<T>(data);
		ret->next = node;
		ret->prev = node->prev;
		if (node->prev != NULL) {
			node->prev->next = ret;
		}
		node->prev = ret;
		this->_length++;
		return ret;
	}

	void remove(ListNode<T>* node) {
		if (node->next != NULL) {
			node->next->prev = node->prev;
		}
		if (node->prev != NULL) {
			node->prev->next = node->next;
		}
		this->_length--;
	}

	void push(T data) {
		this->insertBefore(this->headNode, data);
	}

	T pop() {
		if (this->end()->prev != NULL) {
			T ret = this->end()->prev->data;
			this->remove(this->end()->prev);
			return ret;
		}
		return NULL;
	}

	void push_front(T data) {
		this->insertBefore(this->begin(), data);
	}

	T pop_front() {
		T ret = this->begin()->data;
		this->remove(this->begin());
		return ret;
	}
};
#endif // !List