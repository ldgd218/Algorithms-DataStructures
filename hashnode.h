#ifndef HASH_NODE_H
#define HASH_NODE_H
#include<cstring>

template<typename V>
class hashNode{
	public:
	char *key;
	V value;
	hashNode<V> * next;
	
	hashNode(char *k,V value){
		
		key = new char[strlen(k)+1];
		strcpy(key,k);
		this->value = value;
		next = NULL;
	}
	~hashNode(){
		if(next!=NULL){
			delete next;
		}
		delete [] key;
	}
};
#endif
