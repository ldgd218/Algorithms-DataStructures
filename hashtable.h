#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "hashnode.h"
#include <cstring>
#include<iostream>
using namespace std; 

template<typename V>
class hashTable{
	private:
		int current_size;
		int table_size;
		hashNode<V> ** buckets;

		void rehash(){
			
			hashNode<V>** oldBuckets = buckets;
			int old_table_size = table_size;

			buckets = new hashNode<V>*[2*table_size];
			
			//Added this line after class.
			current_size =0;
			
			table_size *= 2;

			for(int i=0;i<table_size;i++){
				buckets[i] = NULL;
	
			}
			//Iterate over the old table and insert nodes in newTable
				for(int i=0;i<old_table_size;i++){
					if(oldBuckets[i]!=NULL){
							hashNode<V>*temp = oldBuckets[i];
							while(temp!=NULL){
								insert(temp->key,temp->value);
								temp = temp->next;
							}
					delete oldBuckets[i];
					}
					
				}
				delete [] oldBuckets;
		}
		int hashFunction(char *key){
			
			int L = strlen(key);
			int ans = 0;
			int power = 1;
			for(int i=0;i<L;i++){
				
				ans = ans + key[L-i-1]*power;
				ans = ans%table_size;
				power = (power*37)%table_size;
			}

			return ans % table_size;
		}
	public:

		hashTable(){
			 current_size = 0;
			 table_size = 3;
			 buckets = new hashNode<V>*[table_size];
			//Initialize buckets array to NULL.
			 for(int i=0;i<table_size;i++){
				buckets[i] = NULL;
			 }

		}
		void insert(char *key, V value){
			int index = hashFunction(key);
			
			hashNode<V>* myNode = new hashNode<V>(key,value);			
			myNode->next = buckets[index];
			buckets[index] = myNode;
			current_size++;
			float load_factor = current_size/(float)table_size;
			//cout<<"Load factor : "<<load_factor<<endl;
			//cout<<"Currrent Size : "<<current_size <<endl;
			//cout<<"Table Size " << table_size <<endl;
			if(load_factor > 0.7){
				cout<<"Load factor is "<<load_factor <<endl;
				rehash();
			}
		}
		V find(char*key){
			int i = hashFunction(key);
			hashNode<V>* temp = buckets[i];
			while(temp!=NULL){
				if(strcmp(key,temp->key)==0){
					return temp->value;
				}
				temp = temp->next;
			}
			V defaultObject;
			return defaultObject;
		}
		void remove(char *key){
			//HomeWork.
		}

	
		~hashTable(){
			
			for(int i=0;i<table_size;i++){
				
				if(buckets[i]!=NULL){
					delete buckets[i];
				}
			}	
				delete [] buckets;
			buckets = NULL;
		}
		void print(){
			
			for(int i=0;i<table_size;i++){
				cout<<"Bucket "<<i<<"-->";

				if(buckets[i]!=NULL){
					hashNode<V>*temp = buckets[i];
					while(temp!=NULL){
						cout<<temp->key <<"-->";
						temp = temp->next;
					}
				}
				cout<<endl;
			}
		}

};
#endif
