#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

template<typename T>
class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode*left;
	BinaryTreeNode*right;
	
	BinaryTreeNode(T d):data(d),left(NULL),right(NULL){}
};
#endif
