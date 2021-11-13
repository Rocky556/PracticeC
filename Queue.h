#pragma once
#ifndef Queue
#include<List.h>

using namespace std;
template<typename T>
class Queue {
private:
	List<T>* _arr;
	unsigned int _length;
public:
	Queue() {
		this->_arr = new List<T>();
		this->_length = 0;
	}
	Queue(T data) {
		this->_arr = new List<T>(data);
		this->_length = 1;
	}
	T pop() {
		if (this->_arr > 0) {
			this->_length--;
			return this->_arr->pop_front();
		}
		else {
			return NULL;
		}
	}
	void push(T data) {
		this->_arr->push(data);
		this->_length++;
	}

	void forNext(void (*cb)(T data)) {
		this->_arr->forNext(cb);
	}

	unsigned int length() {
		return this->_length;
	}
};
#endif // !Queue
