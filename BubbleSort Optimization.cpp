//best case complexity--> O(n), when array is already sorted
//worst case O(n*n)
#include <bits/stdc++.h>
using namespace std;
int BubbleSort(int a[],int n)
{
	bool swapped;
	for(int i=0;i<n-1;i++)
	{
		swapped=false;
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				swapped=true;
			}
		}
		//if no two element is swapped by inner loop,
		//that means already sorted
		if(swapped == false)
			break;
	}
}
int main()
{
	int a[]={1,2,4,6,8,3,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	BubbleSort(a,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
}