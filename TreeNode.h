#pragma once
#ifndef TreeNode
#include<Stack.h>
#include<Queue.h>
#include<vector>
#include<string>

template<typename T>
class TreeNode {
private:
	TreeNode<T>* _parent;
	vector<TreeNode<T>*> _children;
public:
	string  name;
	T data;
};
#endif // !TreeNode
