#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
#include<cmath>
using namespace std;

BinaryTreeNode<int>* insertInBST(BinaryTreeNode<int> *root,int element){
	if(root==NULL){
		BinaryTreeNode<int>* myNode = new BinaryTreeNode<int>(element);
		return myNode;
	}

	if(root->data > element){
		root->left = insertInBST(root->left,element);
	}
	else{
		root->right = insertInBST(root->right,element);
	}
	return root;
}

bool isBST(BinaryTreeNode<int> * root, int minV,int maxV){
	if(root==NULL){
		return true;
	}
if(root->data>=minV && root->data<maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){return true;}
	
	else{
	return false;
	}
}

class HBPair{
	public:
		int height;
		bool balanced;
};

HBPair isBalancedOptimised( BinaryTreeNode<int> *root){
	HBPair p;

	if(root==NULL){
		p.height =0;
		p.balanced = true;
		return p;
	}

	HBPair left = isBalancedOptimised(root->left);
	HBPair right = isBalancedOptimised(root->right);
	
	p.height = max(left.height,right.height) + 1;

	if((abs(right.height-left.height)<=1)&&left.balanced&& right.balanced)		{
		p.balanced = true;
	}
	else{
		p.balanced = false;
	}
	return p;
}

BinaryTreeNode<int>* arrayToBST( int a[],int start,int end){
	if(start>end){
		return NULL;
	}
	int mid = (start+end)/2;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(a[mid]);
	root->left = arrayToBST(a,start,mid-1);
	root->right = arrayToBST(a,mid+1,end);
	return root;
}


//Time complexity of this function is O(height).
BinaryTreeNode<int>* findInBST(BinaryTreeNode<int> *root , int key){
		if(root==NULL)
			return NULL;

		if(key == root->data){
			return root;
		}

		if(key < root->data){
			return findInBST(root->left,key);
		}
		else{
			return findInBST(root->right,key);
		}
}





BinaryTreeNode<int>* takeBST(){
	BinaryTreeNode<int>*root = NULL;

	int element;
	cout<<"Enter the nodes of the tree until -1 ";
	cin>>element;

	while(element!=-1){
		root = insertInBST(root,element);
		cin>>element;
	}
	return root;
}

class LLPair{
public:
	BinaryTreeNode<int> *head;
	BinaryTreeNode<int> *tail;
};

LLPair BSTtoLinkedList(BinaryTreeNode<int> *root){
		
		LLPair p;

		if(root==NULL){
			p.head = NULL;
			p.tail = NULL;
			return p;
		}
		//Postorder Traversal.
		LLPair leftLL = BSTtoLinkedList(root->left);
		LLPair rightLL = BSTtoLinkedList(root->right);
		
		if(leftLL.head==NULL && rightLL.head==NULL){
			p.head = root;
			p.tail = root;
			return p;

		}

		else if(leftLL.head==NULL && rightLL.head!=NULL){
				p.head = root;
				root->right = rightLL.head;
				p.tail = rightLL.tail;
				return p;
		}
		else if(rightLL.head==NULL && leftLL.head!=NULL){
			p.head = leftLL.head;
			p.tail = root;
			leftLL.tail->right = root;
			return p;
		}
		else{
			leftLL.tail->right = root;
			root->right = rightLL.head;
			p.head = leftLL.head;
			p.tail = rightLL.tail;
			return p;
		}
}



template<typename T>
BinaryTreeNode<T>* takeInput(){
	
	T data;
	cout<<"Enter the root data";
	cin>>data;

	
	BinaryTreeNode<T> *root = new BinaryTreeNode<T>(data);
	queue<BinaryTreeNode<T>* > q;
	q.push(root);

	while(!q.empty()){
		BinaryTreeNode<T> * f = q.front();
		q.pop();
		
		T leftData,rightData;
		int count;
		cout<<"Enter the left & right child of  "<<f->data<<" ";
		cin>>leftData;
		if(leftData!=-1){
			f->left = new BinaryTreeNode<T>(leftData);
			q.push(f->left);
		}
		cin>>rightData;
		if(rightData!=-1){
			f->right = new BinaryTreeNode<T>(rightData);
			q.push(f->right);
		}

	}
return root;
}

void print(BinaryTreeNode<int> *root){
	if(root==NULL){
		return;
	}

	cout<<"Parent :"<<root->data <<endl;
	cout<<"Children :";
	if(root->left){
		cout<<root->left->data;
	}
	cout<<"  ";
	if(root->right){
		cout<<root->right->data;
	}
	cout<<endl<<endl;
	print(root->left);
	print(root->right);

}
void mirror(BinaryTreeNode<int>* root){
	if(root==NULL)
		return;

	BinaryTreeNode<int>*temp = root->left;
	root->left = root->right;
	root->right = temp;
	
	//Recursively Mirror the left and right subtrees.
	mirror(root->left);
	mirror(root->right);
}
BinaryTreeNode<int>* find(BinaryTreeNode<int>* root,int key){
	if(root==NULL)
		return NULL;

	if(root->data ==key){
		return root;
	}

	BinaryTreeNode<int>* leftAns = find(root->left,key);
	if(leftAns!=NULL){
			return leftAns;
	}
	else{
	BinaryTreeNode<int>* rightAns = find(root->right,key);
	return rightAns;
	}
}

void preOrderPrint(BinaryTreeNode<int> * root){
	if(root==NULL)
		return;

	cout<<root->data <<" ";
	preOrderPrint(root->left);
	preOrderPrint(root->right);
}
void inOrderPrint(BinaryTreeNode<int> *root){
	if(root==NULL){
		return ;
	}

	inOrderPrint(root->left);
	cout<<root->data<<" ";
	inOrderPrint(root->right);
}
void postOrderPrint(BinaryTreeNode<int> *root){
	if(root==NULL){
		return;
	}
	postOrderPrint(root->left);
	postOrderPrint(root->right);
	cout<<root->data<<" ";
}
void levelOrderPrint(BinaryTreeNode<int> *root){

queue<BinaryTreeNode<int> * > q;
q.push(root);
q.push(NULL);

while(!q.empty()){
	BinaryTreeNode<int> * f = q.front();
	if(f ==NULL){
		cout<<endl;
		q.pop();
		if(!q.empty()){
			q.push(NULL);
		}
	}
	else{
		q.pop();
		cout<<f->data<<" ";
		if(f->left!=NULL){
			q.push(f->left);
		}
		if(f->right!=NULL){
			q.push(f->right);
			}
		}
	}

}
int height(BinaryTreeNode<int> * root){
	if(root==NULL)
		return 0;

	int h1 = height(root->left);
	int h2 = height(root->right);

	return max(h1,h2) + 1;
}

int diameter(BinaryTreeNode<int> * root){
	if(root==NULL)
		return 0;

	int option1 = diameter(root->left);
	int option2 = diameter(root->right);
	int option3 = height(root->left) + height(root->right);
	return max(max(option1,option2),option3);
}
class Pair{
public:
	int diameter;
	int height;
};
//------------------Diameter Fast.
Pair diameterFast(BinaryTreeNode<int> * root){
	Pair p;
	if(root==NULL){
		p.diameter = 0;
		p.height = 0;
		return p;
	}

	Pair leftTree = diameterFast(root->left);
	Pair rightTree = diameterFast(root->right);

	int option1 = leftTree.diameter;
	int option2 = rightTree.diameter;
	int option3 = leftTree.height + rightTree.height;

	p.diameter = max( max(option1,option2), option3);
	p.height =  max(leftTree.height,rightTree.height)  + 1;
	return p;
}
int countNodes(BinaryTreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	return 1+ countNodes(root->left) + countNodes(root->right);
}


BinaryTreeNode<int>* buildTree(int inorder[],int preorder[],int start,int end){
//Base Cases
	static int preIndex=0;
	//Base Case.
	if(start==end){
		BinaryTreeNode<int> *leaf = new BinaryTreeNode<int>(inorder[start]); 
		preIndex++;
		return leaf;
	}
	if(start>end){
		return NULL;
	}

	//Main part.
		int index;
		int key = preorder[preIndex];
		//Search for the index in the Inorder Array.
		for(int i=start;i<=end;i++){
			if(key == inorder[i]){
				index = i;
				break;
			}
		}
	
	//Build the current Node.
	 BinaryTreeNode<int> *myNode = new BinaryTreeNode<int>(preorder[preIndex]);
	 preIndex++;
	 //build left and right subtress recursively and attach them to current node.
	 myNode->left = buildTree(inorder,preorder,start,index-1);
	 myNode->right = buildTree(inorder,preorder,index+1,end);
	return myNode;
}


int main(){

BinaryTreeNode<int> *root = NULL;
//Call to a tempated func
//root = takeInput<int>();
//Normal function call
print(root);

root = takeBST();
cout<<"PreOrder ";
preOrderPrint(root);
cout<<endl;
cout<<"InOrder ";
inOrderPrint(root);
cout<<endl;
cout<<"Post Order";
postOrderPrint(root);
cout<<endl;
cout<<"Level Order "<<endl;
levelOrderPrint(root);
/*
cout<<"Height of Tree is "<<height(root);
cout<<endl;
cout<<"Diameter of Tree is "<<diameter(root)<<endl;
cout<<"Fast Diamter of Tree is "<<diameterFast(root).diameter<<endl;

int inorder[] = { 4,2,1,5,6,3,7};
int preorder[] = {1,2,4,3,5,6,7};
BinaryTreeNode<int>* newTreeRoot = buildTree(inorder,preorder,0,6);
cout<<"Newly Constructed Tree is "<<endl;
levelOrderPrint(newTreeRoot);
mirror(newTreeRoot);
levelOrderPrint(newTreeRoot);
*/

/*
LLPair linkedlist = BSTtoLinkedList(root);
BinaryTreeNode<int> *temp = linkedlist.head;
while(temp!=NULL){
	cout<< temp->data<<"<=> ";
	temp = temp->right;
}
cout<<" NULL ";
*/

if(isBST(root,-1000000,1000000)){
		cout<<"It is a BST ";
}
mirror(root);
if(isBST(root,-10000,10000)){
	cout<<"After mirroring , it is a BST ";
}
else{
	cout<<"Not a BST after mirroring ";
	
}


return 0;
}

