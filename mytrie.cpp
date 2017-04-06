#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
public:
	char data;
	bool isTerminal;
	unordered_map<char,TrieNode* > map;
	TrieNode(char d){
		data = d;
		isTerminal = false;
	}
};

class Trie{
	TrieNode* root;
	int words;

public:
	Trie(){
		root = new TrieNode('\0');
		words = 0;
	}
	void addWordHelper(char *word,TrieNode* root){
			//Base Case
			if(word[0]=='\0'){
				root->isTerminal = true;
				return;
			}
			//Recursive Case.
			char current_char = word[0];
			//If not found.
			if( root->map.find(current_char) == root->map.end()){
				 
				TrieNode* childNode = new TrieNode(current_char);
				root->map[current_char] = childNode;
				root = childNode;
			}
			else{
				root = root->map.find(current_char)->second;
			}
			addWordHelper(word+1,root);

	}

	bool findWord(char *word){
			
			TrieNode* start = root;

			for(int i=0;word[i]!='\0';i++){
					char current_char = word[i];

					if(start->map.find(current_char)==start->map.end()){
						return false;
					}
					else{
						start = start->map.find(current_char)->second;
					}
			}			
			return start->isTerminal==true?true:false;
	}

	void addWord(char *word){
			words++;
			addWordHelper(word,root);
	}

};


int main(){
	char words[][100]={"apple","mango","banana","bat","cat","ball","dont","do"};
	char searchwords[][100] = {"man","mango","bal","ball","do"};

	
	Trie t;
	for(int i=0;i<8;i++){
		t.addWord(words[i]);
	}

	for(int i=0;i<5;i++){
		if(t.findWord(searchwords[i])){
			cout<<searchwords[i]<<" exists in the trie !";
			cout<<endl;
		}
	}



}

