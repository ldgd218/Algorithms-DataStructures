#include <bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i)
{
	int largest = i;
	int l= 2*i+1;
	int r=2*i+2;
	//if left child is larger than root
	if(l<n && a[l]>a[largest])
	{
		largest=l;
	}
	//if right child is larger than root
	if(r<n && a[r]>a[largest])
	{
		largest=r;
	}
	//if largest is not root
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		//recursively heapify the affected subtree
		heapify(a,n,largest);
	}
}
void heapsort(int a[],int n)
{
	//build heap
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
	//one by one extract an element from the heap
	for(int i=n-1;i>=0;i--)
	{
		//move the current root to the end
		swap(a[0],a[i]);
		//call max heapify on the reduced heap
		heapify(a,i,0);
	}
}
int main()
{
	int a[]={6,4,2,6,7,2,5,4};
	int n=sizeof(a)/sizeof(a[0]);
	heapsort(a,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}