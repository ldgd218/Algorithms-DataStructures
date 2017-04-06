#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include<iostream>
#include<vector>
using namespace std;


class PriorityQueue{
	vector<int> v;
	int current_size;
	int index;

		void heapify(int i){
			int left = 2*i;
			int right = 2*i + 1;

			int min_index = i;
			if(left < index && v[left] < v[i]){
				min_index = left;
			}
			if(right < index && v[right] < v[min_index]){
				min_index = right;
			}
		
			if(i!=min_index){
				swap(v[i],v[min_index]);
				heapify(min_index);
			}
		}

	public:
		PriorityQueue(){
			v.push_back(-1);
			current_size = 0;
			index =1;
		}

		void push(int data){
			v.push_back(data);
			index = index + 1;
			current_size++;

			int i = index - 1;
			//Upar le jao...
			while(i>1){
				int parent = i/2;
				if(v[i] < v[parent]){
					swap(v[i],v[parent]);
					i = i/2;
				}
				else{
					break;
				}
			}	
		}
		bool isEmpty(){
			return current_size==0?true:false;
		}
		bool size(){
			return current_size;
		}

		int getMin(){
			return v[1];
		}
		void pop(){
			int last_element = v[index-1];
			swap(v[1],last_element);
			v.pop_back();
			index = index - 1 ;
			current_size = current_size - 1;
			heapify(1);
		}
};
#endif 
