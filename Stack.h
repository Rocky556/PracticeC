#pragma once
#ifndef Stack
#include<List.h>

using namespace std;
template<typename T>
class Stack {
private:
	List<T>* _arr;
	unsigned int _length;
public:
	Stack() {
		this->_arr = new List<T>();
		this->_length = 0;
	}
	Stack(T data) {
		this->_arr = new List<T>(data);
		this->_length = 1;
	}
	T pop() {
		if (this->_arr > 0) {
			this->_length--;
			return this->_arr->pop();
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
		this->_arr->forPrev(cb);
	}

	unsigned int length() {
		return this->_length;
	}
};
#endif // !Stack

